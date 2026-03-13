#include<bits/stdc++.h>
using namespace std;

void primeNumberBeforN(int n){
    if(n==2){
        cout<<"2 ";
    }
    int i=3;
    while(i<=n){
        bool isPrime=true;
        for(int j=2; j<i; j++){
            if(i%j==0)
            {
                isPrime=false;
                break;
            }
        }
        if(isPrime)
        {
            cout<<i<<" ";
        }
        
        i++;
    }
}

int main(){
    int n;
    cin>>n;
     
    primeNumberBeforN(n);

    return 0;

}