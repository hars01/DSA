#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;

    for(auto &c: s){ // & important hai lagana kya ki tabi change hoga charcter string ka
        if(c>='a' && c<='z')
        c=c-32;
    }
    
    cout<<s<<endl;
}