#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    while(b){
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int lcm1(int a, int b){

    return (a*b)/gcd(a,b);
}

int gcd(int a, int b){
     if(a==0)
    return b; 

    return gcd(b%a, a);
}

int main(){
    int a, b;
    cin>>a;
    cin>>b;
 
    cout<<lcm1(a,b)<<" "<<gcd(a, b);
}