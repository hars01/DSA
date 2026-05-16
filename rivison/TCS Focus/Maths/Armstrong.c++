#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    int sum=0;
    int temp=n;
    while(n>0){
       int rem=n%10;
       sum+=rem*rem*rem;
       n/=10;
    }

    if(sum==temp)
     cout<<"It is Armstrong Number";
    else
    cout<<"It is not an Armstrong Number";

    return 0;
}