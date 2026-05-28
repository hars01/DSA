#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool topologicalSortBFS(int V, vector<int> adj[]) {
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

            vector<int> topo;
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

                if(topo.size()==V)
                return true;

                return false;
        }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto &it : prerequisites){
             adj[it[1]].push_back(it[0]);
        }

        // for(int i=0; i<prerequisites.size(); i++){
        // for(int j=0; j<2; j++){
        //     adj[prerequisites[i][0]].push_back(prerequisites[i][1]);  
        //  }
        // }

        return topologicalSortBFS(numCourses, adj);
    }
};

int main(){
    int V, E;
    cout << "Enter number of courses: ";
    cin >> V;

    cout << "Enter number of prerequisites: ";
    cin >> E;

    vector<vector<int>> prerequisites(E, vector<int>(2));

    cout << "Enter prerequisites:\n";

    for(int i=0; i<E; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

             //OR 

    // vector<pair<int, int>> prerequisites(2);
    // for(int i=0; i<2; i++){
    //     int u, v;
    //     cin>>u>>v;
    //     prerequisites[i]={u, v};
    // }
 
    Solution sol;
    cout<<" 0->false , 1->true : "<<sol.canFinish(V, prerequisites);
}



// Problem :
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1. Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]. Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
// return true if you can finish all courses. Otherwise, return false.

// Approach :
// We can use topological sort to determine if there is a cycle in the graph. If there is a cycle, then it is not possible to finish all courses. If there is no cycle, then it is possible to finish all courses.
// We can use Kahn's algorithm for topological sorting, which uses BFS. We first calculate the indegree of each vertex. Then we add all vertices with indegree 0 to the queue. We then process each vertex in the queue, and for each of its neighbors, we decrease their indegree by 1. If any neighbor's indegree becomes 0, we add it to the queue. If we can process all vertices, then there is no cycle and we can finish all courses. If we cannot process all vertices, then there is a cycle and we cannot finish all courses.
// Time Complexity : O(V + E) where V is the number of vertices and E is the number of edges.
// Space Complexity : O(V + E) for the adjacency list and the indegree array.


// IP :
// 4
// 0 1
// 0 2
// 1 3  
// 2 3

// OP :
// 1 (true)

// Dry run :
// V = 4
// prerequisites = [[0,1],[0,2],[1,3],[2,3]]
// adj = [[1, 2], [3], [3], []]
// indegree = [0, 1, 1, 2]
// q = [0]      
// topo = [0]
// indegree = [0, 0, 1, 2]
// q = [1]
// topo = [0, 1]
// indegree = [0, 0, 1, 1]
// q = [2]
// topo = [0, 1, 2]
// indegree = [0, 0, 0, 1]
// q = [3]
// topo = [0, 1, 2, 3]
// indegree = [0, 0, 0, 0]
// q = []
// topo.size() = 4
// V = 4
// return true


