
#include <iostream>
#include "Hospital.h"
#include "Priority.h"
#include "Djikstra.h"
#include "Input.h"
#include "DispatchRequest.h"
#include "EmergencyResource.h"

using namespace std;

int main() {
    cout << "=== InfernoX Wildfire Emergency Dispatch System ===\n\n";

    // 1. Hospital management
    Hospital hospital(100, "Graphic Era Hospital", 3, 10, 50);
    cout << "--- Hospital ---\n";
    hospital.display();

    // 2. Fire priority calculation
    Priority firePriority(8, 800, 12, 5, 7);
    cout << "\n--- Fire Priority ---\n";
    cout << "Priority score: "
         << firePriority.calculate_priority() << "\n";

    // 3. Road network and shortest route
    Dijkstra planner(4);
    planner.addRoad(0, 1, 5);
    planner.addRoad(0, 2, 2);
    planner.addRoad(1, 3, 3);
    planner.addRoad(2, 3, 4);

    cout << "\n--- Route Planning ---\n";
    planner.shortestPath(0, 3);

    // 4. Emergency input (interactive; uncomment to test)
    // INPUT fire;
    // fire.getInput();
    // fire.displayInput();

    // 5. Emergency resource
    Emergency_res truck(101, "Fire Truck", 0, 5000);
    cout << "\n--- Emergency Resource ---\n";
    truck.display();

    // 6. Dispatch request
    DispatchRequest request(1, 101, 3, "Fire Truck");
    cout << "\n--- Dispatch Request ---\n";
    request.display();
    request.assignResource(truck.getid());
    truck.dispatch();
    request.dispatch();
    request.display();

    cout << "\nIntegration test finished.\n";
    return 0;
}
