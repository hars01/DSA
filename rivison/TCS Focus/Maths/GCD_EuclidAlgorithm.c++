#include<bits/stdc++.h>
using namespace std;

int gcd1(int a, int b){ //Euclid
    while(b!=0){
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int gcd2(int a, int b){
    int mini=min(a, b);
     
    while(mini>0){
        if(a%mini==0 && b%mini==0)
        {
            break;
        }
        mini--;
    }
    return mini;
}

int main() {
    int a, b;
    cin >> a;
    cin>>b;

    cout<<gcd1(a, b)<<" "<<gcd2(a,b);
    return 0;
}