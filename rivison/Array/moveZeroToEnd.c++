#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
          vector<int> movezero(vector<int> arr){
            int n=arr.size();
            int j=0;
            for(int i=0; i<n; i++){
                if(arr[i]!=0)
                arr[j++]=arr[i];
            }

            while(j<n){
                arr[j++]=0;
            }

            return arr;
          }
};


int main(){
    Solution obj;
    cout<<"Enter size of Array: ";
    int n;
    cin>>n;
    cout<<"Enter value of Array: "<<endl;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }


    vector<int> res=obj.movezero(arr);

    cout<<"Array after moving zero: ";

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<(i == res.size() - 1 ? "" : ", ");
    }
    
    return 0;
}

