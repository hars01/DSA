#include<bits/stdc++.h>
using namespace std;


class Solution {
    private:
        void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid){
            int n=grid.size();
            int m=grid[0].size();
            vis[i][j]=1;
            queue<pair<int, int>> q;
            q.push({i, j});

            while(!q.empty())
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();


                for(int delrow=-1; delrow<=1; delrow++){
                    for(int delcol=-1; delcol<=1; delcol++){
                        int nrow=x+delrow;
                        int ncol=y+delcol;
                        
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]!='0' && vis[nrow][ncol]!=1) {
                            vis[nrow][ncol]=1;
                            q.push({nrow, ncol});
                        }
                    }
                } 
            }
        }
    public:
        int numIsland(vector<vector<char>> &grid) {
            int n=grid.size();
            int m=grid[0].size();

            vector<vector<int>> vis(n, vector<int>(m, 0));
            int cnt=0;

            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && grid[i][j] == '1'){
                        cnt++;
                        bfs(i, j, vis, grid);
                    }
                }
            }
            return cnt;
        }
};

int main() {
    int n,m;
    cout<<"Enter Row Size : ";
    cin>>n;
    cout<<"Enter Column Size : ";
    cin>>m;
    vector<vector<char>> grid(n, vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    Solution ss;
    int result= ss.numIsland(grid);
    cout<<"Number of Island : "<<result;

    return 0;
}