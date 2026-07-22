#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        int memoization(int i, int j, vector<vector<int>> &cost, vector<vector<int>> &dp){
            if(i==0 && j==0) return dp[i][j]=cost[0][0];
            if(i<0 || j<0) return INT_MAX;

            if(dp[i][j] != -1) return dp[i][j];

            int top=cost[i][j]+memoization(i-1, j, cost, dp);
            int left=cost[i][j]+memoization(i, j-1, cost, dp);

            return dp[i][j]=min(top, left);
        }

        int tabulation(int n, int m, vector<vector<int>> &cost){
            vector<vector<int>> dp(n, vector<int>(m, 0));

            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(i==0 && j==0) return dp[i][j];
                    
                    else {
                        int top=0, left=0;
                        if(i>0)
                        top=cost[i][j]+dp[i-1][j];
                        if(j>0)
                        left=cost[i][j]+dp[i][j-1];

                        dp[i][j]=min(top, left);
                    }
                }
            }

            return dp[n-1][m-1];
        }
    public:
       int  minimumPathsum(int n, int m, vector<vector<int>> &cost){
           vector<vector<int>> dp(n, vector<int>(m, -1));

           return memoization(n-1, m-1, cost, dp);
        //    return tabulation(n, m, cost);
       }

};

int main(){
    int n, m;
    cout<<"n : ";
    cin>>n;

    cout<<"m : ";
    cin>>m;

    vector<vector<int>> cost(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>cost[i][j];
        }
    }

    Solution sol;
    int res = sol.minimumPathsum(n, m, cost);

    cout<<"Minimum Cost : "<<res;

}