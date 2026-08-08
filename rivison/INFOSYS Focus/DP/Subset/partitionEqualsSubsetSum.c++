// Problem : Partition Equal Subset Sum
// Given a set of positive numbers, find if we can partition it into two subsets such that
// the sum of elements in both subsets is equal.
// Example:
// Input: arr[] = {1, 5, 11, 5}
// Output: true
// Explanation: The array can be partitioned as {1, 5, 5} and {11}.

// Approach: The problem can be solved using dynamic programming. The idea is to find the total sum of the array and then check if there is a subset with sum equal to half of the total sum. If such a subset exists, then the other subset will also have the same sum, and we can partition the array into two subsets with equal sum.
// The time complexity of this approach is O(n*sum) where n is the number of elements in the array and sum is the total sum of the array. The space complexity is also O(n*sum) for the dp array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
       bool memoization(int i, vector<int>& arr, int T, vector<vector<int>>& dp){
            // if(T==0) return 1;
            // if(i==0){
            //     if(arr[i]==T) return 1;
            //     return 0;
            // }

            if(T<=0)
            return true;

            if(i==0)
            return arr[0]==T;

            if(dp[i][T] != -1) return dp[i][T];

            bool notTake = memoization(i-1, arr, T, dp);
            bool Take = false;
            if(arr[i]<=T) Take=memoization(i-1, arr, T-arr[i], dp);

            return dp[i][T] = Take || notTake;
       }

       bool partitionSumCheck(vector<int>& arr, int n, int T){
        vector<vector<int>> dp(n, vector<int>(T+1, -1));

        return memoization(n-1, arr, T, dp);
       }

};

int main(){
    int n;
    cout<<"Size : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter "<<n<<" Elements in an Array"<<endl;
    int sum=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    Solution sol;

    
    if(sum%2 != 0) {
    cout<<"False";
    } else {
    int Target = sum/2;
    cout<<"Target Sum : "<<Target<<endl;
    if(sol.partitionSumCheck(arr, n, Target) == 1){
        cout<<"True";
    }else {
        cout<<"False";
    }
    }

    return 0;

}