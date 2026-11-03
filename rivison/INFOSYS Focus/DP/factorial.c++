#include<bits/stdc++.h>
using namespace std;

// Factorial of a Number by usoing Memoization
class Solution{
    private:

        int memoization(int n, vector<int> &dp){
            if(n==0) return 1;

            if(dp[n]!=-1) return dp[n];

            return dp[n]=n*memoization(n-1, dp);
        }

    public:
        int factorial(int n){
            // return recursion(n);
            vector<int> dp(n+1, -1);
            return memoization(n, dp);
        }
};

int main(){
    int n;
    cin>>n;

    Solution sol;
    cout<<sol.factorial(n)<<endl;
}