#include<bits/stdc++.h>
using namespace std;

string minimumWindowSubstring(string s, string t){
    int n=s.size(), m=t.size();
    int l=0, r=0, cnt=0, stIndex=-1, minimum=INT_MAX;
    unordered_map<char, int> mp;

    for(int i=0; i<n; i++){
        mp[t[i]]++;
    }

    while(r<n){
        if(mp[s[r]]>0){
            cnt++;
        }
        mp[s[r]]--;

        while(cnt==m){
            if((r-l+1)<minimum){
                minimum=(r-l+1);
                stIndex=l;
            }
            mp[s[l]]++;
            if(mp[s[l]]>0){
                cnt--;
            }
            l++;
        }
        r++;
    }

    return s.substr(stIndex, minimum);
}

int main(){
    string s = "AKBJCDEFGADBC";
    string t = "ABC";

    cout<<minimumWindowSubstring(s, t);
    return 0;
}