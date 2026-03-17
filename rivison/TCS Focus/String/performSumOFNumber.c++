#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int sum=0; 
    for(char c: s){
        sum+=(c-'0');
    }

    cout<<sum;
}