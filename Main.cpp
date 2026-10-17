
#include <iostream>
#include <limits>
#include "integrated/Input.h"
#include "integrated/Priority.h"
#include "integrated/Dijkstra.h"
#include "integrated/DispatchRequest.h"
#include "integrated/EmergencyResource.h"
#include "integrated/DispatchManager.h"

using namespace std;

int main() {
    cout << "=== InfernoX Wildfire Emergency Dispatch ===\n\n";

    // 1. Collect wildfire information
    INPUT input;
    input.getInput();

    cout << "\nEnter the numeric location ID of the fire (0-3): ";
    int destination;
    cin >> destination;

    input.displayInput();

    // 2. Calculate incident priority
    Priority priority(
        static_cast<int>(input.getSeverity()),
        input.getNumberOfPeople(),
        static_cast<float>(input.getWindspeed()),
        1.0f,
        static_cast<int>(input.getDistanceFromPopulatedArea())
    );

    cout << "\nCalculated incident priority: "
         << priority.calculate_priority() << '\n';

    // 3. Set up the road network
    Dijkstra planner(4);
    planner.addRoad(0, 1, 5);
    planner.addRoad(0, 2, 2);
    planner.addRoad(1, 3, 3);
    planner.addRoad(2, 3, 4);

    // 4. Register available resources
    DispatchManager manager(planner, 1);

    Emergency_res truck(101, "Fire Truck", 0, 5000);
    Emergency_res tanker(102, "Water Tanker", 1, 3000);

    manager.AddResource(truck);
    manager.AddResource(tanker);

    // 5. Choose a resource type and create a request
    cout << "\nRequired resource (Fire Truck / Water Tanker): ";
    string resourceType;
    cin >> ws;
    getline(cin, resourceType);

    int incidentID = 101;
    int requestID = manager.createRequest(
        incidentID, destination, resourceType
    );

    // 6. Process and display the dispatch
    cout << "\n--- Processing Request ---\n";
    manager.process_pending_request();

    manager.displayallRequest();
    manager.displayallResources();

    // 7. Ask whether to complete the dispatched request
    cout << "\nComplete this request now? (1 = Yes, 0 = No): ";
    int complete;
    cin >> complete;

    if (complete == 1) {
        manager.completeRequest(requestID);
        manager.displayallResources();
    }

    return 0;
}
