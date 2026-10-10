#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>
#include <utility>

using namespace std;

class Dijkstra {
private:
    // {destination, distance}
    vector<vector<pair<int, int>>> graph;

public:
    // Constructor
    Dijkstra(int locations) {
        graph.resize(locations);
    }

    // Add an undirected road
    void addRoad(int u, int v, int distance) {
        if (u < 0 || u >= graph.size() ||
            v < 0 || v >= graph.size()) {
            cout << "Invalid location ID!" << endl;
            return;
        }

        if (distance < 0) {
            cout << "Road distance cannot be negative!" << endl;
            return;
        }

        graph[u].push_back({v, distance});
        graph[v].push_back({u, distance});
    }

    // Find shortest distances and route
    void shortestPath(int source, int destination) {
        int n = graph.size();

        // Validate source and destination
        if (source < 0 || source >= n ||
            destination < 0 || destination >= n) {
            cout << "Invalid source or destination!" << endl;
            return;
        }

        vector<int> dist(n, INT_MAX);
        vector<int> parent(n, -1);

        dist[source] = 0;

        // Min-priority queue: {distance, location}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, source});

        while (!pq.empty()) {
            int currentDistance = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Skip outdated entries
            if (currentDistance > dist[u]) {
                continue;
            }

            // Check neighbouring locations
            for (auto edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;

                int newDistance = dist[u] + weight;

                if (newDistance < dist[v]) {
                    dist[v] = newDistance;
                    parent[v] = u;

                    pq.push({newDistance, v});
                }
            }
        }

        cout << "\nStarting location: " << source << endl;

        cout << "\nShortest distances from source:\n";

        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) {
                cout << i << " : INF" << endl;
            } else {
                cout << i << " : " << dist[i] << endl;
            }
        }

        // Check whether destination is reachable
        if (dist[destination] == INT_MAX) {
            cout << "\nDestination is unreachable!" << endl;
            return;
        }

        // Reconstruct shortest path
        vector<int> path;
        int current = destination;

        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }

        // Print route in correct order
        cout << "\nShortest path: ";

        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];

            if (i > 0) {
                cout << " -> ";
            }
        }

        cout << "\nTotal distance: "
             << dist[destination] << endl;
    }
};

int main() {
    Dijkstra planner(4);

    // Add roads: source, destination, distance
    planner.addRoad(0, 1, 5);
    planner.addRoad(0, 2, 2);
    planner.addRoad(1, 3, 3);
    planner.addRoad(2, 3, 4);

    cout << "Graph created successfully!" << endl;

    // Find shortest route from location 0 to location 3
    planner.shortestPath(0, 3);

    return 0;
}