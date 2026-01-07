#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int majority(vector<int> nums){
        int cnt=0;
        int key=nums[0];
        for(int i=1; i<nums.size(); i++){
             if(nums[i]==key){
             cnt++;
               if(cnt>((nums.size())/2))
               return key;
             }
             else{
                key=nums[i];
                cnt--;
             }
        }

        int orCnt=0;
        for(int i=0; i<nums.size(); i++){
             if(key==nums[i])
             orCnt++;
        }
        if(orCnt>((nums.size())/2))
            // return key;//to show element
            return orCnt;//to show count
            
        cout<<"Count of Majority Element "<<key<<" is "<<orCnt;
        return -1;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    Solution obj;
    int res=obj.majority(nums);
    cout<<"Majority Element = "<<res;
    return 0;
}