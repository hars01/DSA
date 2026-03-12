#include<bits/stdc++.h>
using namespace std;

int nthPrimeNumber(int n){
    if(n==1)
    return 2;


    int i=3, ans=0, cnt=1;
    while(cnt!=n){
         bool isPrime=true;

         for(int j=2; j<i; j++){
            if(i%j==0){
            isPrime=false;
            break;
            }
         }
         if(isPrime){
            ans=i;
            cnt++;
         }
         i++;
    }

    return ans;
}

int main() {
    int n;
    cin>>n;

    cout<<nthPrimeNumber(n);

    return 0;
}