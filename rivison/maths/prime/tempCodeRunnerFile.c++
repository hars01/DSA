#include<bits/stdc++.h>
using namespace std;

void primeNumberToN(int n){
    if(n==1)
    cout<<"1"<<" ";
     for(int i=2; i*i<n; i++){
        if(n%i==0){
           cout<<i<<" ";
           n=n/i; 
        }
     }

     if(n>2)
     cout<<n;
     
}

int main(){
    int n;
    cin>>n;

    primeNumberToN(n);

    return 0;

}
