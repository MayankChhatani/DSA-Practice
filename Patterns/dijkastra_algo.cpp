Dijkstra’s Algorithm - Overview:

Dijkstra's algorithm finds the shortest path from a source node to all other nodes in a weighted graph.

Required Data Structures:

Adjacency List (vector<vector<pair<int, int>>> adj):

Stores the graph where each node has a list of neighbors and weights (time or cost to reach them).

Example: adj[u].push_back({v, w}) means there's an edge from node u to node v with weight w.

Distance Array (vector<int> dist):

Keeps track of the shortest time (or distance) from the source node to all other nodes.

Initially, all nodes are set to infinity (INT_MAX), except the source node which is set to 0.

Priority Queue (priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq):

A min-heap used to efficiently get the node with the smallest distance (time) next.

It stores pairs of (time, node) and helps in processing nodes in the correct order.
#include <bits/stdc++.h>
using namespace std;

