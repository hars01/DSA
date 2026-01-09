#include<bits/stdc++.h>
using namespace std;

string remVowel(string s){
    vector<char> vowel={'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'};

    for(int i=0; i<s.size(); i++){
        if(find(vowel.begin(), vowel.end(), s[i]) != vowel.end()){
            s=s.replace(i, 1, "");
            i-=1;
        }
    }
    return s;
}

bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
    return true;
    return false;
}


string remVowel2(string s){
    string res=" ";
    for(char c: s){
        if(!isVowel(c))
        res.push_back(c);
    }
    return res;
}


int main(){
    string s;
    getline(cin, s);

    cout<<remVowel2(s);
    return 0;
}