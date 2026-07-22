#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int memoization(int i, int j, vector<vector<int>> arr){
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        if (j < 0 || j >= m) return 1e9;
        if(i==0) return arr[0][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int d=arr[i][j]+memoization(i-1, j, arr);
        int lg=arr[i][j]+memoization(i-1, j-1, arr);
        int rg=arr[i][j]+memoization(i-1, j+1, arr);

        return dp[i][j]=min(d, min(lg, rg));
    }

    int tabulation(vector<vector<int>> arr){
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        for(int j=0; j<m; j++){
            dp[0][j]=arr[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                int d=arr[i][j]+dp[i-1][j];
                int ld=arr[i][j];
                if(j-1>=0) ld+=dp[i-1][j-1];
                else ld+=1e9;
                int rd=arr[i][j];
                if(j+1<m) rd+=dp[i-1][j+1];
                else rd+=1e9;

                dp[i][j]=min(d, min(ld, rd));

            }
        }

        int mini=1e9;
        for(int j=0; j<m; j++){
           mini=min(mini, dp[n-1][j]);
        }

        return mini;
    }

    int memoization_max(int i, int j, vector<vector<int>> arr){
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        if (j < 0 || j >= m) return -1e9;
        if(i==0) return arr[0][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int d=arr[i][j]+memoization_max(i-1, j, arr);
        int lg=arr[i][j]+memoization_max(i-1, j-1, arr);
        int rg=arr[i][j]+memoization_max(i-1, j+1, arr);

        return dp[i][j]=max(d, max(lg, rg));
    }

    int tabulation_max(vector<vector<int>> arr){
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        for(int j=0; j<m; j++){
            dp[0][j]=arr[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                int d=arr[i][j]+dp[i-1][j];
                int ld=arr[i][j];
                if(j-1>=0) ld+=dp[i-1][j-1];
                else ld+=-1e9;
                int rd=arr[i][j];
                if(j+1<m) rd+=dp[i-1][j+1];
                else rd+=-1e9;

                dp[i][j]=max(d, max(ld, rd));

            }
        }

        int maxi=-1e9;
        for(int j=0; j<m; j++){
           maxi=max(maxi, dp[n-1][j]);
        }

        return maxi;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // int mini=1e9;
        // for(int i=0; i<n; i++){
        //    mini = min(mini, memoization(n-1, i, matrix));
        // }
        // return mini;

        return tabulation(matrix); 
    }

    int maxFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // int maxi=-1e9;
        // for(int i=0; i<n; i++){
        //    maxi = max(maxi, memoization_max(n-1, i, matrix));
        // }
        // return maxi;

        return tabulation_max(matrix); 
    }
};


int main() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }

    Solution obj;
    cout<<obj.minFallingPathSum(matrix)<<endl;

    // cout<<obj.maxFallingPathSum(matrix)<<endl;

}