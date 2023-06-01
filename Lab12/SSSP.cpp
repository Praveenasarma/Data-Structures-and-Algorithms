#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Node struct represents a node in the graph
struct Node {
    int vertex; // Vertex index
    int time;   // Time from the source
};

// Comparison operator for Node objects
struct CompareNode {
    bool operator()(Node const& n1, Node const& n2) {
        return n1.time > n2.time;
    }
};

// Dijkstra's algorithm to find shortest paths in a weighted graph
void dijkstra(vector<vector<int>>& graph, int source) {
    int num_vertices = graph.size();
    
    vector<int> time(num_vertices, INT_MAX); // Array to store the shortest times
    
    time[source] = 0; // Time from the source vertex to itself is 0
    
    priority_queue<Node, vector<Node>, CompareNode> pq; // Priority queue to select the node with the smallest time
    
    pq.push({source, 0}); // Add the source node to the priority queue with a time of 0
    
    while (!pq.empty()) {
        int u = pq.top().vertex; // Get the node with the smallest time from the priority queue
        pq.pop();
        
        for (int v = 0; v < num_vertices; ++v) {
            if (graph[u][v]) { // If there is an edge between u and v
                int new_time = time[u] + graph[u][v]; // Calculate the new time
                
                if (new_time < time[v]) { // If the new time is smaller than the current time of v
                    time[v] = new_time; // Update the time of v
                    
                    pq.push({v, new_time}); // Add v to the priority queue with its new time
                }
            }
        }
    }
    
    //cout << "From City " << source << " => " << endl;

    int total_time = 0;

    for (int i = 0; i < num_vertices; ++i) {
        cout << "City " << i << ": " << time[i] << endl; // Print the shortest times from the source to all other vertices
        total_time += time[i];
        
    }
    cout << endl;

    //To find average time taken from a city to other cities
    //cout << "Average time taken from city " << source << " to other cities: " << total_time/5 << endl <<endl;
}

int main() {

    int V = 6; // Number of vertices in the graph
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    for (int i = 0; i < V; ++i) {
        dijkstra(graph, i); // Call Dijkstra's algorithm for each vertex in the graph
    }
    
    return 0;
}
