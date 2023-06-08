#include <bits/stdc++.h>
using namespace std;

#define V 6

void primMST(int graph[V][V], int startNode) {
    vector<int> key(V, INT_MAX);                // Key values used to pick minimum weight edge in cut
    vector<bool> mstSet(V, false);              // To track vertices included in MST
    vector<int> parent(V, -1);                  // Array to store constructed MST
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Priority queue to store edges

    pq.push(make_pair(0, startNode));           // Start with the given startNode
    key[startNode] = 0;                         // Key value of startNode is 0

    while (!pq.empty()) {
        int u = pq.top().second;                 // Extract the vertex with minimum key value
        pq.pop();

        if (mstSet[u])
            continue;                            // Skip if the vertex is already included in MST

        mstSet[u] = true;                        // Include vertex u in MST

        for (int v = 0; v < V; v++) {
            int weight = graph[u][v];            // Check all adjacent vertices of u

            if (weight && !mstSet[v] && weight < key[v]) {
                parent[v] = u;                    // Update the parent of v
                key[v] = weight;                  // Update the key value of v
                pq.push(make_pair(key[v], v));    // Add v to the priority queue
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " -- " << i << "\t   " << key[i] << endl;
}

int main() {
    int adjacencyMatrix[V][V] = {{0, 3, 0, 0, 0, 1},
                                 {3, 0, 2, 1, 10, 0},
                                 {0, 2, 0, 3, 0, 5},
                                 {0, 1, 3, 0, 5, 0},
                                 {0, 10, 0, 5, 0, 4},
                                 {1, 0, 5, 0, 4, 0}};

    primMST(adjacencyMatrix, 0);

    return 0;
}
