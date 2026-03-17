#include<bits/stdc++.h>
using namespace std;

int LargestSubstring(string s){
    int maxLen=0, len=0;
    for(int i=0; i<s.size(); i++){
        vector<int> mp(256);
        for(int j=i; j<s.size(); j++){
            if(mp[s[j]]==1)
            break;
            len=j-i+1;
            maxLen=max(maxLen, len);
            mp[s[j]]=1;
        }
    }
    return maxLen;
}

int LargestSubstring(string s){
    int maxLen=0, len=0;
    for(int i=0; i<s.size(); i++){
        vector<int> mp(256);
        for(int j=i; j<s.size(); j++){
            if(mp[s[j]]==1)
            break;
            len=j-i+1;
            maxLen=max(maxLen, len);
            mp[s[j]]=1;
        }
    }
    return maxLen;
}

int main() {

    string s;
    cin>>s;

    cout<<LargestSubstring(s);

}