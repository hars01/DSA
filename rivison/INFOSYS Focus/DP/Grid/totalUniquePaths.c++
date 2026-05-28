#include<bits/stdc++.h>
using namespace std;

class Solution {
    int memoization(int i, int j, vector<vector<int>> &dp){
        if(i==0 && j==0)
        return 1;

        if(i<0 || j<0)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int up=memoization(i-1, j, dp);
        int left=memoization(i, j-1, dp);

        return dp[i][j]=up+left;
    }

    int tabulation(int m, int n, vector<vector<int>> &dp){
        dp[0][0]=1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0)
                dp[0][0]=1;

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


    int spaceOptimization(int m, int n){
        vector<int> prev(n, 0);

        for(int i=0; i<m; i++){
            vector<int> temp(n, 0);
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                temp[j]=1;
                }
                else{
                int up=0, left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=temp[j-1];
                temp[j]=up+left;
                }
            }
            prev=temp;
        }
        return prev[n-1];
    }

    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // return memoization(m-1, n-1, dp);
        // return tabulation(m, n, dp);
        return spaceOptimization(m, n);
    }
};

int main(){
    int m;
    cin>>m;
    int n;  
    cin>>n;
    Solution s;
    cout<<s.uniquePaths(m, n)<<endl;
    return 0;
}