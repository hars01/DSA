#include<iostream>
using namespace std;

int main() {
   string s;
   cin>>s;
   

   for(auto &c: s){
      if(c>='A' && c<='Z')
       c=c+32;
   }
   
   cout<<s<<endl;
}