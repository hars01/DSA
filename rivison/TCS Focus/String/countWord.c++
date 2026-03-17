#include<bits/stdc++.h>
using namespace std;

int main() {
   string s;
   getline(cin, s);

  int count=0;
  bool isWord=false;
  for(auto c: s){
     if(c!=' ' && !isWord){
         count++;
         isWord=true;
    }
    else {
       isWord=false;
    }
    
  }
  
cout<<count;
        
 
}