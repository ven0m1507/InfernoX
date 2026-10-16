
#include <iostream>
#include <string>
using namespace std;

class DispatchRequest {
private:
    int requestID;
    int incidentID;
    int destinationLocation;
    string resourceType;
    string status;
    int assignedResourceID;

public:
    // Constructor
    DispatchRequest(int reqID, int incID,
                    int destination, string type)
        : requestID(reqID),
          incidentID(incID),
          destinationLocation(destination),
          resourceType(type),
          status("Pending"),
          assignedResourceID(-1) {}

    // Getters
    int getRequestID() const {
        return requestID;
    }

    int getIncidentID() const {
        return incidentID;
    }

    int getDestinationLocation() const {
        return destinationLocation;
    }

    string getResourceType() const {
        return resourceType;
    }

    string getStatus() const {
        return status;
    }

    int getAssignedResourceID() const {
        return assignedResourceID;
    }

    // Assign a resource
    void assignResource(int resourceID) {
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

    // Dispatch the resource
    void dispatch() {
        if (status != "Approved") {
            cout << "Assign a resource before dispatching.\n";
            return;
        }

        status = "Dispatched";

        cout << "Request #" << requestID
             << " dispatched successfully.\n";
    }

    // Complete the request
    void completeRequest() {
        if (status != "Dispatched") {
            cout << "Only dispatched requests can be completed.\n";
            return;
        }

        status = "Completed";

        cout << "Request #" << requestID
             << " completed.\n";
    }

    // Display request details
    void display() const {
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
};

int main() {
    cout << "DispatchRequest program started!" << endl;

    DispatchRequest request(
        1,
        101,
        3,
        "Fire Truck"
    );

    request.display();

    cout << "\nAssigning resource...\n";
    request.assignResource(201);
    request.display();

    cout << "\nDispatching resource...\n";
    request.dispatch();
    request.display();

    cout << "\nCompleting request...\n";
    request.completeRequest();
    request.display();

    return 0;
}