#include<bits/stdc++.h>
using namespace std;


void integerToString(int n){
    string s;

    while(n>0){
        s=char(n%10+'0')+s;
        n/=10;
    }
    cout<<s;
}


void stringToInteger(string s){
    int num=0;
    for(char c: s){
        num=num*10+(c-'0');
    }
    cout<<num;
}



int main() {
   string s;
   cin>>s;
 
   stringToInteger(s);
 
   int num;
   integerToString(num);

   return 0;
}