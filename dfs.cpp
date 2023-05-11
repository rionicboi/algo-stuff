#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
private:
    int V;                  
    vector<list<int>> adj;  

public:
    Graph(int V) {
        this -> V = V;
        adj.resize(V);
    }


    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void dfs(int v) {
        vector<bool> visited(V, false); 
        dfsUtil(v, visited);
    }

private:
    void dfsUtil(int v, vector<bool>& visited) {
        visited[v] = true; 
        cout << v << " "; 

        for (int u : adj[v]) {
            if (!visited[u]) {
                dfsUtil(u, visited);
            }
        }
    }
};

int main() {
    int V, E, u, v, start;
    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph g(V);
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges: " << endl;
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << "Enter the starting vertex for BFS traversal: ";
    cin >> start;
    cout << "BFS traversal: ";
    g.dfs(start);
    cout << endl;
    return 0;
}
