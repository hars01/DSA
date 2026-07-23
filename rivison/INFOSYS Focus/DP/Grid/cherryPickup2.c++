#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
      int memoization(int i, int j1, int j2, vector<vector<int>> arr) {
        int n=arr.size();
        int m=arr[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        // DP state check
        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }


        // Base case

        if(j1<0 || j1>m-1 || j2<0 || j2>m-1) return -1e9;

        if(i==n-1){
            if(j1==j2) return arr[i][j1];
            else return arr[i][j1]+arr[i][j2];
        }


        // Recursive case 

        int maxi=0;
        for(int dj1=-1; dj1<2; dj1++){
            for(int dj2=-1; dj2<2; dj2++){
                if(j1==j2)
                {
                   maxi=max(maxi, (arr[i][j1]+memoization(i+1, j1+dj1, j2+dj2, arr)));
                } else {
                   maxi=max(maxi, (arr[i][j1]+arr[i][j2]+memoization(i+1, j1+dj1, j2+dj2, arr)));
                }
            }
        }


        // Store the result in dp array and return
        return dp[i][j1][j2]=maxi;
         
      }

      int tabulation(vector<vector<int>> arr) {
        int n=arr.size();
        int m=arr[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m)));

        // Base case
        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){
                if(j1==j2) dp[n-1][j1][j2]=arr[n-1][j1];
                else dp[n-1][j1][j2]=arr[n-1][j1]+arr[n-1][j2];
            }
        }


        //Tabulation(storing the result in dp array)
        int maxi=0;
        for(int i=n-2; i>=0; i--){
            for(int j1=0; j1<m; j1++){
                for(int j2=0; j2<m; j2++){
                    for(int dj1=-1; dj1<2; dj1++){
                       for(int dj2=-1; dj2<2; dj2++){
                        int value=0;
                        if(j1==j2) value=arr[i][j1];
                        else value=arr[i][j1]+arr[i][j2];

                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m){
                            value+=dp[i+1][j1+dj1][j2+dj2];
                        } else {
                            value+=-1e9;
                        }

                        maxi=max(maxi, value);
                       }
                    } 
                    dp[i][j1][j2]=maxi;  
                }
            }
        }
        return dp[0][0][m-1];
      }

    public:
         int cherryPiking(vector<vector<int>> matrix){
            int m=matrix[0].size();
            // return memoization(0, 0, m-1, matrix);
            return tabulation(matrix);
         }
};

int main() {
    int n, m;
    cin>>n;
    cin>>m;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }


   Solution sol;
   cout<<"Answer will be : "<<sol.cherryPiking(arr);

}