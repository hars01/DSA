#include<bits/stdc++.h>
using namespace std;

class Solution {
      public:
      int finding(vector<int> nums){
        int n=nums.size();
        int cnt, maxLen=0;
         for(int i=0; i<n; i++){
            if(nums[i]==1)
            {
                cnt++;
                maxLen=max(maxLen, cnt);
            }
            else{
                cnt=0;
            }
         }
         return maxLen;
      }

      int findingWithSlidingWindow(vector<int> nums){
        int n=nums.size();
        int left=0, right=0;
        int maxLen=0;

        while(right<n){
            if(nums[right]==1){
                right++;
            }
            else{
                left=right+1;
                right++;
            }
            maxLen=max(maxLen, right-left);
        }
        return maxLen;
      }
};

int main(){
     Solution sol;
     int n;
     cout<<"Enter the size of array: ";
     cin>>n;
     vector<int> nums(n);
     cout<<"Enter the elements of array (0s and 1s only): ";
     for(int i=0; i<n; i++){
        cin>>nums[i];
     }  
     int result=sol.findingWithSlidingWindow(nums);
     cout<<"Maximum consecutive 1s in the array is: "<<result<<endl;
     return 0;
}
