#include <bits/stdc++.h>
using namespace std;

class Solution {
    int memoization(int i, int j, vector<vector<int>> &dp, vector<vector<int>> obstacleGrid){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1)
        return 0;

        if(i==0 && j==0)
        return 1;

        if(i<0 || j<0)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int up=memoization(i-1, j, dp, obstacleGrid);
        int left=memoization(i, j-1, dp, obstacleGrid);

        return dp[i][j]=up+left;
    }

    int tabulation(int m, int n, vector<vector<int>> &dp, vector<vector<int>> obstacleGrid){
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i>=0 && j>=0 && obstacleGrid[i][j]==1)
                dp[i][j]=0;
                else if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else{
                    int up=0, left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];

                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }

    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // return memoization(m-1, n-1, dp, obstacleGrid);
        return tabulation(m, n, dp, obstacleGrid);
        // return spaceOptimization(m, n);
    }
};

int main() {
    vector<vector<int>> obstacleGrid={{0,0,0},{0,1,0},{0,0,0}};
    Solution s;
    cout<<s.uniquePathsWithObstacles(obstacleGrid);
}