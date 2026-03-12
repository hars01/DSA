#include<bits/stdc++.h>
using namespace std;

void primeNumberToN(int n){
     cout<<"2"<<" ";
     int i=3, cnt=1;
     while(cnt<n){
        bool isPrime=true;
        for(int j=2; j<i; j++){
           if(i%j==0)
           isPrime=false;
        }

        if(isPrime){
            cout<<i<<" ";
            cnt++;
        }

        i++;
     }  
}

int main(){
    int n;
    cin>>n;
    
    if(n==1)
    cout<<"1";
    else if(n==2)
    cout<<"1 2";
    else if(n>2)
    primeNumberToN(n);

    return 0;
}
