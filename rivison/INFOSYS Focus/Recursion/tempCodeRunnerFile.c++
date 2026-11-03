#include<bits/stdc++.h>
using namespace std;


void fun(int n, string arr[]) {

        if(n==0)
        return ;

        int fDigit = n%10;
        n=n/10;

        fun(n, arr);

        cout<<arr[fDigit]<<" ";
}

int main() {
    int n;
    cin>>n;

    string arr[] = {
        "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"
    };

    fun(n, arr);

    return 0;
}