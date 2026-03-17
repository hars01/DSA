#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

void frequencyUsingHashmap(string s){
    map<char, int> mp;

    for(auto c: s){
        mp[c]++;
    }

    for(auto c : mp){
        cout<<c.first<<" "<<c.second;
    }
}

int main() {
    string s;
    cin>>s;

    sort(s.begin(), s.end());

    for(int i=0; i<s.length(); i++){
        int count=1;
        while(i+1<s.length() && s[i]==s[i+1]){
            count++;
            i++;
        }

        cout<<s[i]<<count;
    }

    cout<<endl;

    string u;
    cin.ignore();
    cin>>u;
    frequencyUsingHashmap(u);
}