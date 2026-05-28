#include<bits/stdc++.h>
using namespace std;

void makeAdjList(int V, vector<int> adj[]){
    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";
    // Taking adjacency list input
    for(int i=0; i<E; i++){

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    // Printing adjacency list
    printList(V, adj);
}

void printList(int V, vector<int> adj[]){
    cout << "\nAdjacency List:\n";
    for(int i=0; i<V; i++){
        cout << i << " -> ";
        for(auto it : adj[i]){
            cout << it << " ";
        }
        cout << endl;
    }
}

void makeAdjMatrix(int V, vector<int> adj[]) {
    cout << "Enter Adjacency Matrix:\n";
    // Taking adjacency matrix input
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            int x;
            cin >> x;
            // If edge exists
            if(x == 1){
                adj[i].push_back(j);
            }
        }
    }
}


int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<int> adj[V];
    // makeAdjList(V, adj);
    makeAdjMatrix(V, adj);


    return 0;
}