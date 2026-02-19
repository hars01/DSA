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

bool printSubseq(int i, vector<int>& res, vector<int>& arr, int k, int sum){
    int n=arr.size();

    if(i==n){
        if(sum==k){
            for(auto it: res)
            cout<<it<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }

    res.push_back(arr[i]);
    sum+=arr[i];
    if(printSubseq(i+1, res, arr, k, sum)==true);
    return true;
    sum-=arr[i];
    res.pop_back();
    if(printSubseq(i+1, res, arr, k, sum)==true);
    return true;

    return false;
}

int main(){
    string s;
    int k;
    cin>>k;
    cin.ignore();
    getline(cin, s);
    vector<int>arr=takeArray2(s);
    vector<int> res;
    
    bool result=printSubseq(0, res, arr, k, 0);
    cout<<result;
}