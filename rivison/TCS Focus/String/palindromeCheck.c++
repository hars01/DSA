#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
   string s;
   cin>>s;
   
   int i=0;
   int j=s.length()-1;
   
   bool flag=1;

   while(i<j){
     if(s[i]!=s[j]){
        flag=0;
         break;
     }
     i++;
      j--;
    }
    
   cout<<flag;
  
}