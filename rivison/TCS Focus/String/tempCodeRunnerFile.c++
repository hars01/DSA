#include<bits/stdc++.h>
using namespace std;

int main() {
   string s;
   getline(cin, s);


   bool cap=false;
   for(auto c: s){
      if(c==' '){
          cap=true;
      }
      else{
        if(cap && c>='a' && c<='z'){
            cout<<char(c-32);
            cap=false;
        }
         else{
             cout<<c;
             cap=false;
         }
     }
  }
  
  return 0;  
}