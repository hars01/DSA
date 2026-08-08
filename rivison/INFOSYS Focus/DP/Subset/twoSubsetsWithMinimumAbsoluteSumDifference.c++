// Partition A Set Into Two Subsets With Minimum Absolute Sum Difference
// Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
// Example:
// Input: arr[] = {1, 6, 11, 5}
// Output: 1
// Explanation: Subset1 = {1, 5, 6}, sum of Subset1 = 12
// Subset2 = {11}, sum of Subset2 = 11
// Absolute difference = |12-11| = 1

// Approach: The problem can be solved using dynamic programming. The idea is to find the total sum of the array and then find the subset with sum closest to half of the total sum. The minimum absolute difference will be the difference between the total sum and twice the sum of this subset.
// The time complexity of this approach is O(n*sum) where n is the number of elements in the array and sum is the total sum of the array. The space complexity is also O(n*sum) for the dp array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
     public:
         int minSubsetSumDiff(vector<int>& arr, int n){
            int totalSum = 0;
            for(int i=0; i<n; i++) totalSum+=arr[i];

            vector<vector<bool>> dp(n, vector<bool>(totalSum+1, 0));
            for(int i=0; i<n; i++) dp[i][0]=true;

            for(int i=1; i<n; i++){
                for(int t=1; t<=totalSum; t++){
                    bool notTake = dp[i-1][t];
                    bool Take = false;
                    if(arr[i]<=t)
                       Take = dp[i-1][t-arr[i]];
                    dp[i][t]=Take||notTake;
                }
            }

            int mini = 1e9;
            for(int S1=0; S1<=totalSum; S1++){
                if(dp[n-1][S1] == true)
                mini = min(mini, abs((totalSum-S1)-S1));
            }
            

             return mini;
         }
};

int main() {
    int n;
    cout<<"Size : ";
    cin>>n;

    cout<<"Enter "<<n<<" Elements of an Array"<<endl; 
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }


    Solution sol;
    cout<<"Answer : "<<sol.minSubsetSumDiff(arr, n);
}