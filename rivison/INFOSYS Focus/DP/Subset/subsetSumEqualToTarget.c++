#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        bool memoization(int i, vector<int>& arr, int T, vector<vector<int>>& dp){
            int n=arr.size();

            if(T == 0) return true;
            if(i == 0) {
                if(arr[i] == T) return true;
                return false;
            }

            if(dp[i][T] != -1) return dp[i][T];

            bool notTake = memoization(i-1, arr, T, dp);
            bool Take = false;
            if(T>=arr[i]){
                Take=memoization(i-1, arr, T-arr[i], dp);
            }
         
            return dp[i][T] = Take || notTake;
        }

    int memoizationCount(int i, vector<int>& nums, int T, vector<vector<int>>& dp){
        if(i<0){
        //    if(T==0) return 1;
        //    else return 0;
              return (T == 0) ? 1:0;
        }


        if(dp[i][T] != -1) return dp[i][T];

        int notTake = memoizationCount(i-1, nums, T, dp);
        int Take = 0;
        if(nums[i] <= T){
            Take = memoizationCount(i-1, nums, T-nums[i], dp);
        }

        return dp[i][T] = Take+notTake;

    }
    public:
        bool subsetSumValidate(int n, vector<int> arr, int T){
            vector<vector<int>> dp(n,vector<int>(T+1,-1));
            return memoization(n-1, arr, T, dp);
        }

    int findTargetSumWays(int n, vector<int>& nums, int target) {
        int total_sum = 0;
        for(int num: nums){
            total_sum+=num;
        }

        // Check if the target is completely out of reach or if (total_sum + target) is odd
        if (abs(target) > total_sum || (total_sum + target) % 2 != 0) {
            return 0;
        }

        int S1 = (total_sum + target) / 2;

        vector<vector<int>> dp(n, vector<int>(S1+1, -1));
        return memoizationCount(n-1, nums, S1, dp);
    }

};

int main() {
    int n;
    cout<<"Size (n) : ";
    cin>>n;

    int T;
    cout<<"Target Sum : ";
    cin>>T;

    vector<int> arr(n);

    cout<<"Taking Array of Size n : "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Solution sol;
    bool res = sol.subsetSumValidate(n, arr, T);
    cout<<"Subset Sum eqals to Target is Available : "<< res<<endl;

    int count = sol.findTargetSumWays(n, arr, T);
    cout<<"Number of Subsets with Sum equal to Target: "<< count;
}