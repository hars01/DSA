#include<bits/stdc++.h>
using namespace std;

int countLeaders(vector<int> leaders){
    int n=leaders.size();
    int cnt=0;
    int mx=INT_MIN;
    for(int i=n-1; i>=0; i++){
        if (leaders[i] > mx) 
        { 
            cnt++; 
            mx = leaders[i]; 
        }
    }

    return cnt;
}

int main(){
    vector<int> a={1,2,3,4,5,9,5,3,5,3,6,8,3,4,7,0,6,4,2,};
    cout<<countLeaders(a);
    return 0;
}