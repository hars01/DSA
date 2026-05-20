#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        int recursion(int n, int k){
            if(n==0) return 1;
            if(n<0) return 0;

            int ans=0;
            for(int i=1; i<=k; i++){
                ans+=recursion(n-i, k);
            }
            return ans;
        }

        int memoization(int n, int k, vector<int> &dp){
            if(n==0) return 1;
            if(n<0) return 0;

            if(dp[n]!=-1) return dp[n];

            int ans=0;
            for(int i=1; i<=k; i++){
                ans+=memoization(n-i, k, dp);
            }
            return dp[n]=ans;
        }

         int tabulation(int n, int k){
            vector<int> dp(n+1, 0);
            dp[0]=1;

            for(int i=1; i<=n; i++){
                for(int j=1; j<=k; j++){
                    if(i-j>=0){
                        dp[i]+=dp[i-j];
                    }
                }
            }
            return dp[n];
        }

    public:

        int numOfWays(int n, int k){
            return recursion(n, k);
            // vector<int> dp(n+1, -1);
            // return memoization(n, k, dp);
            // return tabulation(n, k);
            
        }
     
};

int main(){
    int n, k;
    cout<<"Enter N : ";
    cin>>n;
    cout<<"Enter K : ";
    cin>>k;

    Solution ob;
    cout<<"Number of Ways : "<<ob.numOfWays(n, k)<<endl;

    return 0;
}