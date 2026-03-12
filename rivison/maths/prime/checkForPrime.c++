#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n){
    bool isPrime=true;
    for(int i=2; i*i<n; i++){
        if(n%i==0)
        isPrime=false;
    }

    return isPrime;
}

int main(){
    int n; 
    cin>>n;
    
    if(checkPrime(n))
    cout<<"True";
    else
    cout<<"False";

    return 0;
}