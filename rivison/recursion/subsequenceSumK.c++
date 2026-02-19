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

void printSubseq(int i, vector<int>& res, vector<int>& arr, int k, int sum){
    int n=arr.size();

    if(i==n){
        if(sum==k){
            for(auto it: res)
            cout<<it<<" ";
            cout<<endl;
        }
        return;
    }

    res.push_back(arr[i]);
    sum+=arr[i];
    printSubseq(i+1, res, arr, k, sum);
    sum-=arr[i];
    res.pop_back();
    printSubseq(i+1, res, arr, k, sum);
}

int main(){
    string s;
    int k;
    cin>>k;
    cin.ignore();
    getline(cin, s);
    vector<int>arr=takeArray2(s);
    vector<int> res;
    
    printSubseq(0, res, arr, k, 0);
}