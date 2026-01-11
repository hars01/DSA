// Maximum Points You Can Obtain from Cards
// The goal is to pick exactly $k$ elements from either the beginning or the end of an array to maximize their sum.

#include<bits/stdc++.h>
using namespace std;

vector<int> takeArray(string s){
    vector<int> arr;
    stringstream ss(s);

    string temp;
    while(getline(ss, temp, ' ')){
        int num=stoi(temp);
        arr.push_back(num);
    }

    return arr;
}


int getPoint(vector<int> nums, int k){
    int n=nums.size();
    int lsum=0, rsum=0; 

    for(int i=0; i<k-1; i++){
        lsum+=nums[i];
    }

    int maxSum=lsum;
    int rind=n-1;
    for(int i=k-1; i>=0; i--){
        lsum-=nums[i];
        rsum+=nums[rind];
        rind--;

        maxSum=max(maxSum, lsum+rsum);
    }

    return maxSum;

}

int main(){
    string s;
    int k;
    cin>>k;
    cin.ignore();
    getline(cin, s);

    vector<int>arr=takeArray(s);

    // Safety check
    if(k > arr.size()) k = arr.size();

    int res=getPoint(arr,k);
    cout<<res;

}