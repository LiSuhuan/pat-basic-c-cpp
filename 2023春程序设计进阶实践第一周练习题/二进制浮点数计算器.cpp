//
// Created by lenovo on 2023/6/14.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int vertex, vector<int>& traversal) {
    visited[vertex] = true;
    traversal.push_back(vertex);

    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor, traversal);
        }
    }
}

vector<int> depthFirstSearch(vector<vector<int>>& graph, int startVertex) {
    vector<bool> visited(graph.size() + 1, false);
    vector<int> traversal;

    dfs(graph, visited, startVertex, traversal);

    return traversal;
}

int main() {
    int N, M, S;
    cin >> N >> M >> S;

    vector<vector<int>> graph(N + 1); // Vertices are numbered from 1 to N

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> traversal = depthFirstSearch(graph, S);

    if (traversal.size() < N) {
        cout << "Non-connected" << endl;
    } else {
        for (int vertex : traversal) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
