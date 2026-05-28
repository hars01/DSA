#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void topologicalSortBFS(int V, vector<int> adj[], vector<int> &topo) {
            // int indegree[V] = {0};
            vector<int> indegree(V, 0);
            for(int i=0; i<V; i++){
                for(auto it: adj[i]){
                    indegree[it]++;
                }
            }

            queue<int> q;
            for(int i=0; i<V; i++){
                if(indegree[i]==0)
                q.push(i);
            }

            // vector<int> topo;
            while(!q.empty()){
                int node=q.front();
                q.pop();

                topo.push_back(node);

                for(auto it: adj[node]){
                    indegree[it]--;
                    if(indegree[it]==0)
                    q.push(it);
                }
            }

        }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> adj[numCourses];

        // Build graph
        for(auto &it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> topo;
        topologicalSortBFS(numCourses, adj, topo);

        // If topo sort contains all nodes
        if(topo.size() == numCourses)
            return topo;

        return {};
    }
};

int main(){
    int V;
    cout<<"Enter Vertices"<<endl;
    cin>>V;

    int m;
    cin >> m;

    vector<vector<int>> prerequisites(m, vector<int>(2));

    for(int i=0; i<m; i++){
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    // vector<vector<int>> prerequisites(2, vector<int>(2));
    // cout<<"Enter Prerequisites"<<endl;
    //     for(int i=0; i<2; i++){
    //         for(int j=0; j<2; j++){
    //             cout<<"Enter prerequisite "<<i+1<<" "<<j+1<<endl;
    //             cin>>prerequisites[i][j];
    //         }
    //     }

             //OR 

    // vector<pair<int, int>> prerequisites(2);
    // for(int i=0; i<2; i++){
    //     int u, v;
    //     cin>>u>>v;
    //     prerequisites[i]={u, v};
    // }
 
    Solution sol;
    vector<int> res = sol.findOrder(V, prerequisites);
    if(res.empty()){
        cout<<"No valid order of courses exists."<<endl;
    } else {
        cout<<"A valid order of courses is: ";
        for(int course : res){
            cout<<course<<" ";
        }
    cout<<endl;
    }

}




// Problem:
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid
// orderings, return any of them. If it is impossible to finish all courses, return an empty array.

// IP :
// numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// OP :
// A valid order of courses is: 0 1 2 3
// Explanation: There are a total of 4 courses to take. To take course 3
// you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

//Dry Run :
// numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Adjacency List :
// 0 -> 1, 2
// 1 -> 3
// 2 -> 3
// 3 ->
// Indegree Array :
// [0, 1, 1, 2]
// Queue : q.push(0) -> q.push(1) -> q.push(2) -> q.push(3)
// Topological Sort :  
// topo.push_back(0) -> topo.push_back(1) -> topo.push_back(2) -> topo.push_back(3)
// Topological Sort : 0 1 2 3