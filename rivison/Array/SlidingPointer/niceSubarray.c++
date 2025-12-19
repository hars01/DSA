// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fun(vector<int> nums, int k, int n){
        int r=0, l=0, sum=0, cnt=0;

        while(r<n){
            sum+=(nums[r]%2);

            while(sum>k){
                sum-=(nums[l]%2);
                l++;
            }

            cnt+=(r-l+1);

            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int> nums, int k) {
        int n=nums.size();
        return (fun(nums, k, n)-fun(nums, k-1, n));
    }
};

int main()
{
    vector<int>nums({2,2,2,1,2,2,1,2,2,2});
    int k=2;
    
    Solution sol;
    long long ans = sol.numberOfSubarrays(nums, k);
    cout << "Number of subarrays with exactly " << k << " odd numbers = " << ans << '\n';

    // return numberOfSubarrays(nums, k);
    
    return 0;
}
