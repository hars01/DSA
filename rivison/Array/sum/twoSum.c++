#include<bits/stdc++.h>
using namespace std;


int Size(vector<int>nums){
    int count=0;
    for(auto i: nums){
        count++;
    }   
    return count;
}


void sorting(vector<int>nums){ // bubble sort
    for(auto i=0; i<Size(nums); i++){
        for(auto j=i+1; j<nums.size(); j++){
            if(nums[i]>nums[j]){
                swap(nums[i], nums[j]);
            }
        }
    }
}


class Solution {
    public:
        vector<int> twoSum(vector<int> nums, int t){
            for(int i=0; i<nums.size(); i++){
                for(int j=i+1; j<nums.size(); j++){
                    if(nums[i]+nums[j]==t){
                        return {i, j};
                    }
                }
            }
        }
        vector<int> twoSumUsingHashmap(vector<int> nums, int t){
            unordered_map<int, int> mp;
            for(int i=0; i<nums.size(); i++){
                int res=t-nums[i];
                if(mp.find(res)!=mp.end()){ // found
                    return {mp[res], i}; // return indices
                }   
                mp[nums[i]]=i;
            }
        }
        bool twoSumUsingSorting(vector<int> nums, int t){ 
            sorting(nums);

            int l=0, r=nums.size()-1;
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum==t){
                    return true;
                }
                else if(sum<t){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
};


int main(){
    vector<int> nums={2,7,11,15};
    int target;
    cout<<"Enter target sum: ";
    // cin>>target;
    scanf("%d", &target);

    Solution sol;
    vector<int> ans = sol.twoSumUsingHashmap(nums, target);
    cout << "Indices of the two numbers such that they add up to " << target << " are: ";
    for(auto i: ans){
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}