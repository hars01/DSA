#include<bits/stdc++.h>
using namespace std;

class Solution {
    private: 
        int memoization(vector<int>& coins, int amt, vector<int> dp){
            // Base Class
            if(amt==0) return 0;
            if(amt<0) return INT_MAX;

            // Step-2
            if(dp[amt] != -1) return dp[amt];

            // Step-3
            int mini=INT_MAX;
            int n=coins.size();
            for(int i=0; i<n; i++){
                   int ans=memoization(coins, amt-coins[i], dp);

                   if(ans!=INT_MAX)
                   mini=min(mini, ans+1);
            }
            dp[amt]=mini;

            return dp[amt];
        }

        int tabulation(vector<int>& coins, int amt){
            int n=coins.size();

             vector<int> dp(amt+1, INT_MAX);

             // Base Class
             dp[0]=0;

             for(int i=1; i<=amt; i++){
                for(int j=0; j<n; j++){
                    if( i-coins[j]>=0  &&  dp[i-coins[j]]!=INT_MAX ){
                        dp[i]=min( dp[i], 1+dp[i-coins[j]] );
                    }
                }
             }

             if( dp[amt]==INT_MAX )
             return -1;

             return dp[amt];
        }

   public: 

       int minCoins(vector<int>& coins, int amt){
        // Step-1
        vector<int> dp(amt+1, -1);


        // int ans = memoization(coins, amt, dp);
        // if(ans==INT_MAX)
        // return -1;

        int ans = tabulation(coins, amt);

        return ans;
       }
};

int main() {
    int amt; 
    cout<<"Amounts that is Required"<<endl;
    cin>>amt;


    int n; 
    cout<<"Size of Coins Array :"<<endl;
    cin>>n;

    vector<int> coin(n);
    cout<<"Enter Value of "<<n<<" Coins :"<<endl;
    for(int i=0; i<n; i++){
        cin>>coin[i];
    }

    Solution ss;

    int ans=ss.minCoins(coin, amt);

    cout<<"Minimum coins required for amount ("<<amt<<") is : "<<ans<<endl;

    return 0;
}

