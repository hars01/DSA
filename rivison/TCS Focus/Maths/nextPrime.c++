#include<bits/stdc++.h>
using namespace std;

bool primeCheck(int n) {
        if(n<=1)
          return false;
        if(n<=3)
           return true;
        for(int i=3; i<n; i++){
           if(n%i==0)
           return false;
         }
        return true;
}


int main(){
   int n;
   cin>>n;

   if(n<=1)
    cout<<"2"<<endl;
    
   int prime=n;
   bool found=false;
 
   while(!found){
      prime++;
      if(primeCheck(prime))
        found=true;
   }
  cout<<prime;

}