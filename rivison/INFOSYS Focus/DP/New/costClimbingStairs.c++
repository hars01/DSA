#include<bits/stdc++.h>
using namespace std;

class Solution {
    private: 
        int memoization(vector<int>& cost, int n, vector<int>&dp){
            if(n==0)
            return cost[0];

            if(n==1)
            return cost[1];

            if(dp[n] != -1)
            return dp[n];

            dp[n]=cost[n]+min(memoization(cost, n-1, dp), memoization(cost, n-2, dp));

            return dp[n];
        }


        int tabulation(vector<int> cost, int n){
             vector<int> dp(n+1, 0);

             dp[0]=cost[0];
             dp[1]=cost[1];

             for(int i=2; i<n; i++){
                dp[i]=cost[i]+min(dp[i-1], dp[i-2]);
             }

             return dp[n-1];
        }

   public: 

       int miniClimbing(vector<int> cost){
          int n=cost.size();

        //   vector<int> dp(n+1, -1);

        //   int ans=min(memoization(cost, n-1, dp), memoization(cost, n-2, dp));

          int ans=min(tabulation(cost, n-1), tabulation(cost, n-2));


          return ans;
       }
};

int main() {
    int n; 
    cout<<"Size of Cost Array"<<endl;
    cin>>n;

    vector<int> cost(n);
    cout<<"Enter "<<n<<" Costs"<<endl;
    for(int i=0; i<n; i++){
        cin>>cost[i];
    }

    Solution ss;

    int ans=ss.miniClimbing(cost);

    cout<<"Minimum cost required to reach top Of stair is : "<<ans<<endl;

    return 0;
}