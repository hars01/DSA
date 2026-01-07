// Problem Description: Sort an array of 0's 1's & 2's where 0's represent red, 1's represent white & 2's represent blue.
// The sorted array should have all 0's first, then all 1's & all 2's at the end.
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        //Approach 1: Counting Sort
        // Time Complexity: O(n)
        // Space Complexity: O(1)
        vector<int> sortColor(vector<int> nums){
            int cnt0=0, cnt1=0, cnt2=0; 
            for(int i=0; i<nums.size(); i++){
                if(nums[i]==0)
                cnt0++;
                else if(nums[i]==1)
                cnt1++;
                else 
                cnt2++;
            }

            for(int i=0; i<cnt0; i++){
                nums[i]=0;
            }
            for(int i=cnt0; i<cnt0+cnt1; i++){
                nums[i]=1;
            }
            for(int i=cnt0+cnt1; i<nums.size(); i++){
                nums[i]=2;
            }

            return nums;
        }
};

int main(){
    Solution sol;
    cout<<"Enter size of array: ";
    int n;
    cin>>n;
    cout <<"Enter elements(0's, 1's & 2's only): ";
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    vector<int> ans = sol.sortColor(nums);
    cout<<"Sorted array: ";
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}

