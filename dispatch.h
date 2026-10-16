#ifndef DISPATCH_MANAGER_H
#define DISPATCH_MANAGER_H

#include <iostream>
#include <string>
#include<vector>
#include<limits>

// Adding files
#include "dispatchrequest.cpp"
#include "resources.cpp"
#include "route.cpp"
#include "hospital.cpp"
#include "priority.cpp"

class DispatchManager{
   private:
        vector <DispatchRequest> requests;
        vector <Emergency_res> resources;
        Route &routePlanner;
        int nextRequestID;
    public:
        DispatchManager(Route &route_obj,int next_request_id):routePlanner(route_obj),nextRequestID(next_request_id){}
        
        //Add resource
        void AddResource(const Emergency_res &resc){
            resources.push_back(resc);
        }

        //store request
        int createRequest(int incidentID, int destinationLoc,string resourceType){
            DispatchRequest req(nextRequestID, incidentID,destinationLoc,resourceType);   //assigning request to dispatch request class
            requests.push_back(req);
            cout<<"New request created: "<<nextRequestID<<"for incident with incident ID: "<<incidentID<<"at Location : "<<destinationLoc<<endl;
            return nextRequestID;

        }

        // manage route class to handle resources
        int findResource(int destination_Location,const string &Required_Type_of_resource){
            int bestRouteIndex=-1;
            int minDistance=INT_MAX;
            for(int i=0;i<resources.size();i++){                                             ////
                if(resources[i].isavaailable() && resources[i].getType()==Required_Type_of_resource){
                    int dist=routePlanner.getShortestDistance(resources[i].getlocation(),destination_Location);

                   if(dist!=-1 && dist < minDistance){
                    minDistance=dist;
                    bestRouteIndex=i;
                   }
                }
            }
            return bestRouteIndex;
        }

        //to process next pending request
        bool process_pending_request(){
            int pending_index=-1;
            for(int i=0;i<requests.size();i++){
                if(requests[i].getStatus()=="Pending"){
                    pending_index=i;
                    break;
                }
            }
            if(pending_index==-1){
                cout<<"NO PENDING REQUEST!"<<endl;
                return false;
            }
            int temp = findResource(requests[pending_index].getDestinationLocation(),requests[pending_index].getResourceType());
            if(temp!=-1){
                requests[pending_index].assignResource(resources[temp].getid());
                resources[temp].dispatch();
                requests[pending_index].dispatch();
                return true;
              } 
              cout<<" !!WARNING!!\n  No available "<<requests[pending_index].getResourceType()<<"found for id: "<<requests[pending_index].getRequestID()<<endl;
              return false;
        }

        //to complete request and free up resources
        void completeRequest(int requestID){
            int reqIndex=-1;
            for(int i=0;i<requests.size();i++){
                if(requests[i].getRequestID() == requestID){
                    reqIndex=i;
                    break;
                 }
            }
            if(reqIndex==-1){
                cout<<"Request for id :"<<requestID<<"not found"<<endl;
                return;
            }
            int assignedID = requests[reqIndex].getAssignedResourceID();
            requests[reqIndex].completeRequest();
            for(int i=0;i<resources.size();i++){
                if(resources[i].getid()==assignedID){
                    resources[i].makeavailable();
                    cout<<"Ressource with id: "<<assignedID<<"freed from request id: "<<requestID<<endl;
                    return;
                }

            }
        }

        void displayallRequest(){
            cout<<"\n-------ALL DISPATCH REQUESTD-------\n";
            if(requests.size()==0){
                cout<<"NO REQUESTS"<<endl;
                return;
            }
            for(int i=0;i<requests.size();i++){
                requests[i].display();
            }
        }

        void displayallResources(){
            cout<<"\n------ALL EMERGENCY RESOURCES------\n";
            if(resources.size()==0){
                cout<<"NO RESOURCES REGISTERED"<<endl;
                return;
            }
             for(int i=0;i<resources.size();i++){
                resources[i].display();
             }
        }

};
#endif