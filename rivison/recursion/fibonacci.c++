#include<bits/stdc++.h>

using namespace std;

void fibonacciFor(int n){
    int first=0, second=1;
    int next=0;
    for(int i=0; i<n; i++){
        if(i<=1)
        next=i;
        else {
          next=first+second;
          first=second;
          second=next;
        }
        cout<<next<<" ";
    }
}

int fibonacci(int n){
    if(n<1){
        return 0;
    }
    
    if(n==1)
    return 1;

    int ans=fibonacci(n-1)+fibonacci(n-2);
}

void fibRecursion(int n){
    int i=0;
    while(i!=n){
        cout<<fibonacci(i)<<" ";
        i++;
    }
}

int main(){
    int n;
    cin>>n;

    // fibonacciFor(n); //Using For Loop

    fibRecursion(n); //using recursion
    return 0;
}