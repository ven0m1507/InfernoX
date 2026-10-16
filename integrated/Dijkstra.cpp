
#include "Djikstra.h"

#include <iostream>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

Dijkstra::Dijkstra(int locations) {
    graph.resize(locations);
}

void Dijkstra::addRoad(int u, int v, int distance) {
    if (u < 0 || u >= static_cast<int>(graph.size()) ||
        v < 0 || v >= static_cast<int>(graph.size())) {
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

void Dijkstra::shortestPath(int source, int destination) {
    int n = static_cast<int>(graph.size());

    if (source < 0 || source >= n ||
        destination < 0 || destination >= n) {
        cout << "Invalid source or destination!" << endl;
        return;
    }

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    dist[source] = 0;

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

        if (currentDistance > dist[u]) {
            continue;
        }

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != INT_MAX &&
                dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
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

    if (dist[destination] == INT_MAX) {
        cout << "\nDestination is unreachable!" << endl;
        return;
    }

    vector<int> path;
    int current = destination;

    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    cout << "\nShortest path: ";

    for (int i = static_cast<int>(path.size()) - 1; i >= 0; i--) {
        cout << path[i];

        if (i > 0) {
            cout << " -> ";
        }
    }

    cout << "\nTotal distance: " << dist[destination] << endl;
}
