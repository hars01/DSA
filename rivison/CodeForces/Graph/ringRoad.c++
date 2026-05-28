#include<bits/stdc++.h>
using namespace std;

class Solution {

    public:

    int solve(int n, vector<vector<pair<int, int>>> &adj, int totalCost){
        int cost=0;

        int prev=1;
        int curr=adj[1][0].first;


        cost+=adj[1][0].second;
        while(curr!=1){
            for(auto &it: adj[curr]){
                int nxt=it.first;
                int w=it.second;
                if(nxt!=prev){
                    cost+=w;
                    prev=curr;
                    curr=nxt;
                    break;
                }
            }
        }

        return min(cost, totalCost-cost);

    }
};


int main(){
    int n, m;
    cin>>n;

    vector<vector<pair<int, int>>> adj(n+1);
    int totalCost=0;

    for(int i=0; i<n; i++){
        int u, v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,0});
        adj[v].push_back({u,w});

        totalCost+=w;
    }


    Solution sol;
    int res=sol.solve(n, adj, totalCost);
    cout<<res<<endl;

}