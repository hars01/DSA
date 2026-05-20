#include<bits/stdc++.h>
using namespace std;

class Solution {
    int memoization(int ind, vector<int> &arr, vector<int> &dp){
        if(ind==0) return arr[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1){
            return dp[ind];
        }

        int take=arr[ind];
        if(ind>1){
            take+=memoization(ind-2, arr, dp);
        }
        int nottake=0+memoization(ind-1, arr, dp);

        return dp[ind]=max(take, nottake);
    }

    int tabulation(int n, vector<int> &arr){
        vector<int> dp(n, 0);
        dp[0]=arr[0];
        int neg=0;

        for(int i=1; i<n; i++){
            int take=arr[i];
            if(i>1){
                take+=dp[i-2];
            }
            int nottake=0+dp[i-1];

            dp[i]=max(take, nottake);
        }

        return dp[n-1];
    }

    int spaceOptimization(int n, vector<int> &arr){
        vector<int> dp(n, 0);
        int prev=arr[0];
        int prev2=0;

        for(int i=1; i<n; i++){
            int take=arr[i];
            if(i>1){
                take+=prev2;
            }
            int nottake=0+prev;

            int curr=max(take, nottake);

            prev2=prev;
            prev=curr;
        }

        return prev;
    }
public:
    int nonAdjSum(vector<int> arr){
        int n=arr.size();
        vector<int> dp(n, -1);

        // return spaceOptimization(n, arr);
        return tabulation(n, arr);
        // return memoization(n-1, arr, dp);
    }

    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n=nums.size();

        for(int i=0; i<nums.size(); i++){
            if(i!=0)
            temp1.push_back(nums[i]);

            if(i!=n-1)
            temp2.push_back(nums[i]);
        }

        return max(nonAdjSum(temp1), nonAdjSum(temp2));
    }
};

int main(){
    int n;
    cout<<"Enter the number of houses : ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the amount of money in each house : ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    Solution s;
    cout<<"Maximum amount of money that can be robbed is : "<<s.rob(nums)<<endl;

    return 0;
}