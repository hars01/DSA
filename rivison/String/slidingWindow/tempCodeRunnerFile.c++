// Maximum Points You Can Obtain from Cards
// The goal is to pick exactly $k$ elements from either the beginning or the end of an array to maximize their sum.

#include<bits/stdc++.h>
using namespace std;



int useBruteForce(string s){
    int n=s.size();
    int maxLen=0;
        vector<int> hash(256, 0); 

    for(int i=0; i<n; i++){
        
        for(int j=i; j<n; j++){
            if(hash[s[j]]==1)
            break;

            maxLen=max(maxLen, (j-i+1));
            hash[s[j]]==1;
        }
    }
    return maxLen;
}

int useSlindingWindow(string s){
    int n=s.size();
    int maxLen=0;
    vector<int> hash(256, -1);
    int l=0, r=0;

    while(r<n){
        if(hash[s[r]]!=-1)
        {
           if(hash[s[r]]>=l)
           l=hash[s[r]]+1;
        }
        maxLen=max(maxLen, r-l+1);
        hash[s[r]]=r;
        r++;
    }
    return maxLen;
}

int main(){
    string s;
    // int k;
    // cin>>k;
    // cin.ignore();
    getline(cin, s);

    int res1=useBruteForce(s);
    cout<<res1<<endl;

    int res2=useSlindingWindow(s);
    cout<<res2;

}