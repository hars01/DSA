// Longest Subarray with at most K distinct elements
// You've correctly identified that a set alone won't work for the sliding window approach, and you've even commented out the solution: a Frequency Map.

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
    while(getline(ss, temp, ',')){
        int num=stoi(temp);
        arr.push_back(num);
    }

    return arr;
}

int getLength(vector<int> nums, int k){
    int n=nums.size();
    int maxLen=0;
    for(int i=0; i<n; i++){
        set<int> set;
        for(int j=i; j<n; j++){
            set.insert(nums[j]);
            if(set.size()<=k)
            maxLen=max(maxLen, j-i+1);
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
    unordered_map<int, int> mp;
    while(r<n){
        //  if(mp.find(nums[r])==mp.end())
            mp[nums[r]]++;
       
        if(mp.size()>k){
            mp[nums[l]]--;
            if(mp[nums[l]]==0)
            mp.erase(nums[l]);
            l++;
        }


        if(mp.size()<=k){
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