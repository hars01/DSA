#include<bits/stdc++.h>
using namespace std;


// Enter Row Size : 3
// Enter Column Size : 3
// 1 1 1
// 2 2 0
// 2 2 2
// Starting Row : 2
// Starting Column : 0
// New Color Integer : 3
// Number of Island : 
// 1 1 1 
// 3 3 0 
// 3 3 3 

class Solution {
    private:
        void dfs(int sr, int sc, vector<vector<int>> &ans, vector<vector<int>> &grid, int intial, int newClr, int dr[], int dc[]) {
            ans[sr][sc]=newClr;
            int n=grid.size();
            int m=grid[0].size();

            for(int i=0; i<4; i++){
                    
                        int nrow=sr+dr[i];
                        int ncol=sc+dc[i];

                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==intial && ans[nrow][ncol]!=newClr){
                            dfs(nrow, ncol, ans, grid, intial, newClr, dr, dc);
                        }
                    
            }
        }
    public:
        vector<vector<int>> floodFill(int sr, int sc, int newClr, vector<vector<int>> &grid){
            int intial = grid[sr][sc];
            vector<vector<int>> ans=grid;

            int Dr[]={-1, 0, +1, 0};
            int Dc[]={0, -1, 0, +1};

            dfs(sr, sc, ans, grid, intial, newClr, Dr, Dc);

            return ans;
        }
};

int main() {
    int n,m;
    cout<<"Enter Row Size : ";
    cin>>n;
    cout<<"Enter Column Size : ";
    cin>>m;
    vector<vector<int>> grid(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<"Row "<<i<<" Col "<<j<<" : ";
            cin>>grid[i][j];
        }
    }

    int sr, sc, newClr;
    cout<<"Starting Row : ";
    cin>>sr;
    cout<<"Starting Column : ";
    cin>>sc;
    cout<<"New Color Integer : ";
    cin>>newClr;

    Solution ss;
    vector<vector<int>> res= ss.floodFill(sr, sc, newClr, grid);
    cout<<"Number of Island : "<<endl;
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[0].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


