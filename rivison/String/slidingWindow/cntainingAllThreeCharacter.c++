// use only a, b, c
#include<bits/stdc++.h>
using namespace std;



int useBruteForce(string s){
    int n=s.size();
    int count=0;
    for(int i=0; i<n; i++){
        unordered_map<char, int> hash;
        for(int j=i; j<n; j++){
            if(hash[s[j]]==0)
            hash[s[j]]++;
            if(hash.size()>=3 && hash[s[j]]>0)
            count++;
        }
    }
    return count;
}

int useSlindingWindow(string s){
    int n=s.size();
    int count=0, l=0, r=0;
   vector<int>hash(3, -1);
    for(int i=0; i<n; i++){
        hash[s[i]-'a']=i;
        if(hash[0]!=-1 && hash[0]!=-1 && hash[0]!=-1)
        count+=(1+min(hash[0], min(hash[1], hash[2])));
    }
    return count;
}

int main(){
    string s;
    
    getline(cin, s);

    int res1=useBruteForce(s);
    cout<<res1<<endl;

    int res2=useSlindingWindow(s);
    cout<<res2;

}