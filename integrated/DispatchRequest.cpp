
#include "DispatchRequest.h"

#include <iostream>

using namespace std;

DispatchRequest::DispatchRequest(int reqID, int incID,
                                 int destination, string type)
    : requestID(reqID),
      incidentID(incID),
      destinationLocation(destination),
      resourceType(type),
      status("Pending"),
      assignedResourceID(-1) {}

int DispatchRequest::getRequestID() const {
    return requestID;
}

int DispatchRequest::getIncidentID() const {
    return incidentID;
}

int DispatchRequest::getDestinationLocation() const {
    return destinationLocation;
}

string DispatchRequest::getResourceType() const {
    return resourceType;
}

string DispatchRequest::getStatus() const {
    return status;
}

int DispatchRequest::getAssignedResourceID() const {
    return assignedResourceID;
}

void DispatchRequest::assignResource(int resourceID) {
    if (status != "Pending") {
        cout << "Request is not pending.\n";
        return;
    }

    assignedResourceID = resourceID;
    status = "Approved";

    cout << "Resource #" << resourceID
         << " assigned to request #"
         << requestID << ".\n";
}

void DispatchRequest::dispatch() {
    if (status != "Approved") {
        cout << "Assign a resource before dispatching.\n";
        return;
    }

    status = "Dispatched";

    cout << "Request #" << requestID
         << " dispatched successfully.\n";
}

void DispatchRequest::completeRequest() {
    if (status != "Dispatched") {
        cout << "Only dispatched requests can be completed.\n";
        return;
    }

    status = "Completed";

    cout << "Request #" << requestID
         << " completed.\n";
}

void DispatchRequest::display() const {
    cout << "\n----- DISPATCH REQUEST -----\n";
    cout << "Request ID: " << requestID << '\n';
    cout << "Incident ID: " << incidentID << '\n';
    cout << "Destination Location: "
         << destinationLocation << '\n';
    cout << "Required Resource: " << resourceType << '\n';

    if (assignedResourceID != -1) {
        cout << "Assigned Resource ID: "
             << assignedResourceID << '\n';
    } else {
        cout << "Assigned Resource: None\n";
    }

    cout << "Status: " << status << '\n';
    cout << "----------------------------\n";
}
