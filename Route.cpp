#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

class Route {
private:
    vector<vector<pair<int, int>>> adj;

public:

 
    Route(int numberOfLocations) {
        adj.resize(numberOfLocations + 1);
    }

 
    void addRoad(int source, int destination, int distance) {
        adj[source].push_back({destination, distance});
        adj[destination].push_back({source, distance});
    }

    vector<int> shortestDistance(int source) {

        int n = adj.size();

        vector<int> distance(n, INT_MAX);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        distance[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {

            int currentDistance = pq.top().first;
            int currentLocation = pq.top().second;

            pq.pop();

            if (currentDistance > distance[currentLocation])
                continue;

            for (auto edge : adj[currentLocation]) {

                int nextLocation = edge.first;
                int roadDistance = edge.second;

                if (currentDistance + roadDistance
                    < distance[nextLocation]) {

                    distance[nextLocation] =
                        currentDistance + roadDistance;

                    pq.push({
                        distance[nextLocation],
                        nextLocation
                    });
                }
            }
        }

        return distance;
    }

    // Get shortest distance between locations
    int getShortestDistance(int source, int destination) {

        vector<int> distance = shortestDistance(source);

        if (distance[destination] == INT_MAX)
            return -1;

        return distance[destination];
    }

    // Display krne ke liye 
    void displayRoutes() {

        for (int i = 1; i < adj.size(); i++) {

            cout << "Location " << i << " : ";

            for (auto edge : adj[i]) {
                cout << " -> "
                     << edge.first
                     << " (" << edge.second << " km)";
            }

            cout << endl;
        }
    }
};

int main(){

Route Obj1(30);

}