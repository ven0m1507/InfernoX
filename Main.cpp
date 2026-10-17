
#include "integrated/DispatchManager.h"
#include <iostream>
#include "Hospital.h"
#include "Priority.h"
#include "Dijkstra.h"
#include "Input.h"
#include "DispatchRequest.h"
#include "EmergencyResource.h"

using namespace std;


int main() {
    cout << "=== InfernoX Wildfire Emergency Dispatch System ===\n";

    // Create road network
    Dijkstra planner(4);
    planner.addRoad(0, 1, 5);
    planner.addRoad(0, 2, 2);
    planner.addRoad(1, 3, 3);
    planner.addRoad(2, 3, 4);

    // Create manager
    DispatchManager manager(planner, 1);

    // Register emergency resources
    Emergency_res truck(101, "Fire Truck", 0, 5000);
    Emergency_res tanker(102, "Water Tanker", 1, 3000);

    manager.AddResource(truck);
    manager.AddResource(tanker);

    // Create and process dispatch request
    int requestID = manager.createRequest(101, 3, "Fire Truck");

    cout << "\n--- Processing Request ---\n";
    manager.process_pending_request();

    cout << "\n--- Current Requests ---\n";
    manager.displayallRequest();

    cout << "\n--- Current Resources ---\n";
    manager.displayallResources();

    cout << "\n--- Completing Request ---\n";
    manager.completeRequest(requestID);

    cout << "\n--- Final Resource Status ---\n";
    manager.displayallResources();

    return 0;
}
