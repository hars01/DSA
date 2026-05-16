#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
    vis[node]=1;
    ls.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int> dfsFunction(int V, vector<int> adj[]){
     int vis[V+1]={0};
     int st=0;
     vector<int> ls;
     dfs(st, adj, vis, ls);
     return ls;
}

int main() {

    int V, E;

    cout<<"Enter number of vertices : ";
    cin>>V;

    cout<<"Enter number of edges : ";
    cin>>E;

    vector<int> adj[V];

    cout<<"Enter edges : "<<endl;

    // Undirected graph
    for(int i=0; i<E; i++) {

        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> res = dfsFunction(V, adj);

    cout<<"BFS Traversal : ";

    for(int node : res) {
        cout<<node<<" ";
    }

    return 0;
}