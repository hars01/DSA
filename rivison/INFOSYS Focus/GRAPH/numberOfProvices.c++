#include<bits/stdc++.h>
using namespace std;

class Solution {
    private: 
         void dfs(vector<int> grid[], int idx, vector<int> &vis){
               vis[idx]=1;
               for(auto it: grid[idx]){
                if(!vis[it]){
                    dfs(grid, it, vis);
                }
               }
         }

        void bfs(vector<int> grid[], int idx, vector<int> &vis){
                queue<int> q;
                q.push(idx);

            while(!q.empty()){
                    int node=q.front();
                    q.pop();

                for(auto c: grid[node]){
                    if(!vis[c]){
                        vis[c]=1;
                        q.push(c);
                    }
                }
            }
        }

    public:
        int numberProvinces(int V, vector<vector<int>> &grid){
            vector<int> adj[V];
            
            for(int i=0; i<V; i++) {
                for(int j=0; j<V; j++) {

                    if(grid[i][j] == 1 && i != j) {
                      adj[i].push_back(j);
                      adj[j].push_back(i);
                    }
                }
            }


            vector<int> vis(V, 0);
            int c=0;

            for(int i=0; i<V; i++){
                if(!vis[i]){
                    c++;
                    bfs(adj, i, vis);
                    //.....OR
                    // dfs(V, grid, i, vis);
                }
            }


            return c;
        }
};


int main() {

    int n;

    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for(int i=0; i<n; i++) {

        for(int j=0; j<n; j++) {

            cin >> grid[i][j];
        }
    }

    Solution ss;

    int count = ss.numberProvinces(n, grid);

    cout << "The Number of Provinces are : " << count;

    return 0;
}