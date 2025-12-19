#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> reduceDuplicate(vector<int> nums){
        int i=0;
        int n=nums.size();

        if(n == 0) return nums; // Edge case handle karne ke liye

        for(int j=1; j<n; j++){
            if(nums[i]!=nums[j]){ 
                i++;               
                nums[i]=nums[j];
                // i++;
            }
        }

        // i ke baad wale saare elements ko 0 karne ke liye
        for(int k=i+1; k<n; k++){
            nums[k]=0;
        }

        cout<<"New length of array after removing duplicates: "<<i+1<<endl;
        
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
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}   