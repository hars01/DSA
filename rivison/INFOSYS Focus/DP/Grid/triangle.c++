#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
          int memoization(int i, int j, vector<vector<int>>arr)
          {
            int n=arr.size();
            vector<vector<int>> dp(n, vector<int>(n, -1));

            if(i==n-1) return arr[n-1][j];

            if(dp[i][j]!=-1) return dp[i][j];

            int d=arr[i][j]+memoization(i+1, j, arr);
            int dg=arr[i][j]+memoization(i+1, j+1, arr);

            return dp[i][j]= min(d, dg);
          }

          
          int tabulation(vector<vector<int>> arr){
            int n=arr.size();
            vector<vector<int>> dp(n, vector<int>(n, 0));

            for(int j=0; j<n; j++){
                dp[n-1][j] = arr[n-1][j];
            }

            for(int i=n-2; i>=0; i--){
                for(int j=i; j>=0; j--){
                    int d=arr[i][j]+dp[i+1][j];
                    int dg=arr[i][j]+dp[i+1][j+1];
                    dp[i][j]=min(d, dg);
                }
            }

            return dp[0][0];
          }
        
};

int main() {
    int n;
    cin>>n;

    vector<vector<int>> arr(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            int x;
            cin>>x;
            arr[i][j]=x;
        }
    }

    Solution obj;
    // cout<<obj.memoization(0, 0, arr)<<endl;

    cout<<obj.tabulation(arr)<<endl;

}