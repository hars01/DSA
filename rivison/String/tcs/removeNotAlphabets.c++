#include <bits/stdc++.h>
using namespace std;

string removeSpecialCharacter(string s){
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        // Store only valid characters
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >='a' && s[i] <= 'z'))
        { 
            s[j] = s[i];
            j++;
        }
    }
    return s.substr(0, j);
}

int main(){
    string s;
    getline(cin, s);

    string res=removeSpecialCharacter(s);
    cout<<res;
    return 0;
}

// Input : $Har*s;h.., 'Mis^hra?
// Output : HarshMishra