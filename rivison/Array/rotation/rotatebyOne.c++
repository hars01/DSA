#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
         vector<int> rotate(vector<int> arr){
            int temp=arr[0];
            for(int i=0; i<arr.size(); i++){
                arr[i-1]=arr[i];
            }
            arr[arr.size()-1]=temp;
            return arr;
         }
};

int main(){
    Solution obj;
    int n, m;
    cout<<"Enter the size of the array: ";
    cin>>n>>m;
    cout<<"Enter the number of rotations: "<<m<<endl;   
    vector<int> arr(n);
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> rotatedArr=obj.rotate(arr);
    for(int i=0; i<rotatedArr.size(); i++){
        cout<<rotatedArr[i]<<" ";
    }
    return 0;
}

//Time Complexity: O(n)         
//Space Complexity: O(1)