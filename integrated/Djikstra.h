
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <utility>

class Dijkstra {
private:
    // {destination, distance}
    std::vector<std::vector<std::pair<int, int>>> graph;

public:
    explicit Dijkstra(int locations);

    void addRoad(int u, int v, int distance);

    void shortestPath(int source, int destination);
};

#endif
