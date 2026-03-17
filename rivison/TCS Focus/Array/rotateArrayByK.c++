#include<bits/stdc++.h>
using namespace std;

void TakeArray(vector<int>& arr){
    string s;
    getline(cin, s);

    stringstream ss(s);
    string temp;

    while(getline(ss, temp, ',')){
        int val=stoi(temp);
        arr.push_back(val);
    }

}

void reversed(vector<int>& arr, int i, int j){
    while(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}

void rotateArray(vector<int>& nums, int k){
    int i=0, j=nums.size();
        reversed(nums, i, j);
        reversed(nums, i, i+k);
        reversed(nums, i+k, j);
}

void PrintArray(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main() {
    vector<int> arr;
    TakeArray(arr);

    int k;
    cin>>k;

    rotateArray(arr, k);

    PrintArray(arr);
}