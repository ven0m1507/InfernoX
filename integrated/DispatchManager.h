
#ifndef DISPATCH_MANAGER_H
#define DISPATCH_MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <climits>

#include "Dijkstra.h"
#include "DispatchRequest.h"
#include "EmergencyResource.h"

class DispatchManager {
private:
    std::vector<DispatchRequest> requests;
    std::vector<Emergency_res> resources;
    Dijkstra& routePlanner;
    int nextRequestID;

public:
    DispatchManager(Dijkstra& route_obj, int next_request_id)
        : routePlanner(route_obj), nextRequestID(next_request_id) {}

    void AddResource(const Emergency_res& resc) {
        resources.push_back(resc);
    }

    int createRequest(int incidentID, int destinationLoc,
                      std::string resourceType) {
        DispatchRequest req(nextRequestID, incidentID,
                            destinationLoc, resourceType);
        requests.push_back(req);

        std::cout << "New request created: " << nextRequestID
                  << " for incident ID: " << incidentID
                  << " at location: " << destinationLoc << std::endl;

        return nextRequestID++;
    }

    int findResource(int destination_Location,
                     const std::string& Required_Type_of_resource) {
        int bestRouteIndex = -1;
        int minDistance = INT_MAX;

        for (int i = 0; i < static_cast<int>(resources.size()); i++) {
            if (resources[i].isavaailable() &&
                resources[i].getType() == Required_Type_of_resource) {

                int dist = routePlanner.getShortestDistance(
                    resources[i].getlocation(), destination_Location);

                if (dist != -1 && dist < minDistance) {
                    minDistance = dist;
                    bestRouteIndex = i;
                }
            }
        }

        return bestRouteIndex;
    }

    bool process_pending_request() {
        int pending_index = -1;

        for (int i = 0; i < static_cast<int>(requests.size()); i++) {
            if (requests[i].getStatus() == "Pending") {
                pending_index = i;
                break;
            }
        }

        if (pending_index == -1) {
            std::cout << "NO PENDING REQUEST!" << std::endl;
            return false;
        }

        int temp = findResource(
            requests[pending_index].getDestinationLocation(),
            requests[pending_index].getResourceType());

        if (temp != -1) {
            requests[pending_index].assignResource(resources[temp].getid());
            resources[temp].dispatch();
            requests[pending_index].dispatch();
            return true;
        }

        std::cout << "WARNING: No available "
                  << requests[pending_index].getResourceType()
                  << " found for request ID: "
                  << requests[pending_index].getRequestID() << std::endl;

        return false;
    }

    void completeRequest(int requestID) {
        int reqIndex = -1;

        for (int i = 0; i < static_cast<int>(requests.size()); i++) {
            if (requests[i].getRequestID() == requestID) {
                reqIndex = i;
                break;
            }
        }

        if (reqIndex == -1) {
            std::cout << "Request ID " << requestID
                      << " not found" << std::endl;
            return;
        }

        int assignedID = requests[reqIndex].getAssignedResourceID();

        if (requests[reqIndex].getStatus() != "Dispatched") {
            std::cout << "Request must be dispatched before completion."
                      << std::endl;
            return;
        }

        requests[reqIndex].completeRequest();

        for (int i = 0; i < static_cast<int>(resources.size()); i++) {
            if (resources[i].getid() == assignedID) {
                resources[i].makeavailable();
                std::cout << "Resource ID " << assignedID
                          << " freed from request ID "
                          << requestID << std::endl;
                return;
            }
        }
    }

    void displayallRequest() const {
        std::cout << "\n------- ALL DISPATCH REQUESTS -------\n";

        if (requests.empty()) {
            std::cout << "NO REQUESTS" << std::endl;
            return;
        }

        for (const auto& request : requests) {
            request.display();
        }
    }

    void displayallResources() const {
        std::cout << "\n------ ALL EMERGENCY RESOURCES ------\n";

        if (resources.empty()) {
            std::cout << "NO RESOURCES REGISTERED" << std::endl;
            return;
        }

        for (const auto& resource : resources) {
            resource.display();
        }
    }
};

#endif
