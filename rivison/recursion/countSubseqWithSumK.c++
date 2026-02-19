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

int printSubseq(int i, vector<int>& arr, int k, int sum){
    int n=arr.size();

    if(i==n){
        if(sum==k){
            return 1;
        }
        return 0;
    }

    sum+=arr[i];
    int l=printSubseq(i+1, arr, k, sum);

    sum-=arr[i];
    int r=printSubseq(i+1, arr, k, sum);

    return l+r;
}

int main(){
    string s;
    int k;
    cin>>k;
    cin.ignore();
    getline(cin, s);
    vector<int>arr=takeArray2(s);
    
    int result=printSubseq(0, arr, k, 0);
    cout<<result;
}