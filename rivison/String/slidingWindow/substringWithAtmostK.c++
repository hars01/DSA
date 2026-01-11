#include<bits/stdc++.h>
using namespace std;



int useBruteForce(string s, int k){
    int n=s.size();
    int maxLen=0;
    // unordered_map<char, int> hash;
    for(int i=0; i<n; i++){
        unordered_map<char, int> hash;
        for(int j=i; j<n; j++){
            hash[s[j]]++;

            if(hash.size()<=k)
            maxLen=max(maxLen, (j-i+1));

            else 
            break;
        }
    }
    return maxLen;
}

int useSlindingWindow(string s, int k){
    int n=s.size();
    int maxLen=0;
    // vector<int> hash(256, -1);
    unordered_map<char, int> hash;
    int l=0, r=0;

    while(r<n){
        hash[s[r]]++;
        if(hash.size()>k){
            hash[s[l]]--;
            if(hash[s[l]]==0)
            hash.erase(s[l]);
            l++;
        }

        if(hash.size()<=k)
            maxLen=max(maxLen, (r-l+1));
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

    int res1=useBruteForce(s, k);
    cout<<res1<<endl;

    int res2=useSlindingWindow(s, k);
    cout<<res2;

}

// Input 2
//       aaabbcd
// Output5
//       5