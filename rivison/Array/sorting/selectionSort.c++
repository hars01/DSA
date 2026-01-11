#include<bits/stdc++.h>
using namespace std;

vector<int> takeInput(string s){
        stringstream ss(s);
        int num;
        vector<int> res;
        while(ss>>num){
            res.push_back(num);
        } 
        return res;
}

vector<int> bSort(vector<int> arr){
    int n=arr.size();
    for(int i=0; i<n-1; i++){
        int min_idx=i;
        for(int j=i+1; j<n; j++){
            if(arr[min_idx]>arr[j])
            {
                min_idx=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=temp;
    }
    return arr;
}

void print(vector<int> arr){
    int n=arr.size();

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    string s;
    getline(cin, s);

    vector<int> nums=takeInput(s);
    print(nums);
    vector<int> res=bSort(nums);
    print(res);
    return 0;
}