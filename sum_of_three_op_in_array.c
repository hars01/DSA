#include <stdio.h>
vector<vector<int>>triple(vector<int>&nums)
{
    vector<vector<int>>result;
    n=nums.size();
    for(int i=0; i<n-2; i++)
    {
        int l=i+1;
        int r=n-1;
        int target=-nums[i];
        while(l<r)
        {
            int sum=nums[l]+nums[r];
            if(sum==target)
            {
                l++;
                r--;
            }
             while(l<r&&nums[l]==nums[l-1])
            {
                l++;
                continue;
            }
            while(l<r&&nums[r]==nums[r+1])
            {
                r--;
                continue;
            }
            result=push_back({nums[i],nums[l],nums[r]});
            else if(target>sum)
                l++;
            else
                r--;
                
           return restult;
        }
    }
}
int main() 
{

    return 0;
}