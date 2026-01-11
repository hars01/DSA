#include<bits/stdc++.h>
using namespace std;

vector<int> takeArray(string s){
    vector<int> arr;
    stringstream ss(s);

    int num;
    while(ss>>num){
        arr.push_back(num);
    }

    return arr;
}

vector<int> takeArray2(string s){
    vector<int> arr;
    stringstream ss(s);

    string temp;
    while(getline(ss, temp, ' ')){
        int num=stoi(temp);
        arr.push_back(num);
    }

    return arr;
}

int getLength(vector<int> nums){
    int n=nums.size();
    int l=0, r, maxLen=0, sum=0;

    for(r=0; r<n; r++){
         sum+=nums[r];
         while((r-l+1)!=sum){
            sum-=nums[l];
            l++;
         }
         maxLen=max(maxLen, r-l+1);
    }
    return maxLen;
}

int main(){
    string s;
    // cin.ignore();
    getline(cin, s);

    vector<int>arr=takeArray2(s);

    int res=getLength(arr);
    cout<<res;

}