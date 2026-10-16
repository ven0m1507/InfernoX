
#ifndef DISPATCH_REQUEST_H
#define DISPATCH_REQUEST_H

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
    DispatchRequest(int reqID, int incID, int destination, string type);

    int getRequestID() const;
    int getIncidentID() const;
    int getDestinationLocation() const;
    string getResourceType() const;
    string getStatus() const;
    int getAssignedResourceID() const;

    void assignResource(int resourceID);
    void dispatch();
    void completeRequest();
    void display() const;
};

#endif
