#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

// Define a structure to represent an edge in the graph
struct Edge {
    int destination;
    int weight;
};

// Function to implement Dijkstra's Algorithm
vector<int> dijkstra(int start, int nodes, vector<vector<Edge>>& graph) {
    vector<int> distance(nodes, INT_MAX); // Distance to each node
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap
    pq.push({0, start});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > distance[currentNode]) continue;

        for (auto& edge : graph[currentNode]) {
            int nextNode = edge.destination;
            int weight = edge.weight;
            if (distance[currentNode] + weight < distance[nextNode]) {
                distance[nextNode] = distance[currentNode] + weight;
                pq.push({distance[nextNode], nextNode});
            }
        }
    }
    return distance;
}

// Function to simulate traffic light adjustments
void updateTrafficLights(vector<vector<Edge>>& graph, int u, int v, int newWeight) {
    for (auto& edge : graph[u]) {
        if (edge.destination == v) {
            edge.weight = newWeight;
            break;
        }
    }
}

int main() {
    // Input: Number of nodes and edges
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    if (!(cin >> nodes >> edges) || nodes <= 0 || edges <= 0) {
        cerr << "Invalid input. Please enter positive integers for nodes and edges." << endl;
        return 1;
    }

    vector<vector<Edge>> graph(nodes);
    
    // Input: Graph edges
    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        if (!(cin >> u >> v >> w) || u < 0 || v < 0 || w < 0 || u >= nodes || v >= nodes) {
            cerr << "Invalid edge. Ensure nodes are within range and weights are positive." << endl;
            return 1;
        }
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // For an undirected graph
    }

    // Input: Start and end nodes
    int start, end;
    cout << "Enter the start and end nodes: ";
    if (!(cin >> start >> end) || start < 0 || end < 0 || start >= nodes || end >= nodes) {
        cerr << "Invalid start or end node." << endl;
        return 1;
    }

    // Find shortest path
    vector<int> distances = dijkstra(start, nodes, graph);
    if (distances[end] == INT_MAX) {
        cout << "No path exists from " << start << " to " << end << endl;
    } else {
        cout << "Shortest distance from " << start << " to " << end << " is: " << distances[end] << endl;
    }

    // Simulate traffic light adjustment
    cout << "\nSimulating traffic light adjustment...\n";
    int u, v, newWeight;
    cout << "Enter the edge (u v) and new weight: ";
    if (!(cin >> u >> v >> newWeight) || u < 0 || v < 0 || newWeight < 0 || u >= nodes || v >= nodes) {
        cerr << "Invalid input for traffic light adjustment." << endl;
        return 1;
    }
    updateTrafficLights(graph, u, v, newWeight);

    // Recalculate shortest path
    distances = dijkstra(start, nodes, graph);
    if (distances[end] == INT_MAX) {
        cout << "No path exists from " << start << " to " << end << endl;
    } else {
        cout << "Updated shortest distance from " << start << " to " << end << " is: " << distances[end] << endl;
    }

    return 0;
}
