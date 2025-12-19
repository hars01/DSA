#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> reduceDuplicate(vector<int> nums){
        int i=0;
        int n=nums.size();
        for(int j=0; j<n; j++){
            if(nums[i]!=nums[j]){                
                nums[i+1]=nums[j];
                nums[j]=0;
                i++;
            }
        }
    
        return nums;
    }
};

int main(){
    Solution obj;
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter "<<n<<" elements in sorted order: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    vector<int> result = obj.reduceDuplicate(nums);

    cout<<"Array after removing duplicates: ";
    for(int i=0; i<=result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}   