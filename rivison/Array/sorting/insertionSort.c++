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
    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--){
            if(arr[j-1]>arr[j])
            {
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
            else{
                break;
            }
        }
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