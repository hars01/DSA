#include<bits/stdc++.h>
using namespace std;

int main() {
   string s;
   getline(cin, s);

   for(auto c: s){
      if(c==' '){
        continue;
      }
      else{
        cout<<c;
      }
  }
  
  return 0;
}