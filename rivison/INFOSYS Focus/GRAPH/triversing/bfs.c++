#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int V, vector<int> grid[]){
   int vis[V]={0};
   queue<int> q;
   q.push(0);
   vector<int> bfs;
   while(!q.empty()){
    int node=q.front();
    q.pop();
    bfs.push_back(node);

    for(auto c: grid[node]){
        if(!vis[c]){
            vis[c]=1;
            q.push(c);
        }
    }
   }
   return bfs;
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

    vector<int> res = bfs(V, adj);

    cout<<"BFS Traversal : ";

    for(int node : res) {
        cout<<node<<" ";
    }

    return 0;
}