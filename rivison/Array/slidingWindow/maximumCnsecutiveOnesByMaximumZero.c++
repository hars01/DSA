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

int getLength(vector<int> nums, int k){
    int n=nums.size();
    int maxLen=0;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            if(nums[j]==0)
            sum++;
            if(sum<=k){
                maxLen=max(maxLen, (j-i+1));
            }
            else
            break;
        }
    }
    return maxLen;
}

int getLengthSlindingPointer(vector<int> nums, int k){
    int n=nums.size();
    int maxLen=0;
    int l=0, r=0, sum=0; 
    while(r<n){
         if(nums[r]==0)
            sum++;

        if(sum>k){
            if(nums[l]==0){
                sum--;
            }
            l++;
        }
        if(sum<=k){
            maxLen=max(maxLen, r-l+1);
        }
        r++;
    }
    return maxLen;
}

int main(){
    string s;
    int k;
    cin>>k;
    cin.ignore();
    getline(cin, s);

    vector<int>arr=takeArray2(s);

    int res=getLength(arr, k);
    cout<<res<<endl;

    int res2=getLengthSlindingPointer(arr, k);
    cout<<res2;

}