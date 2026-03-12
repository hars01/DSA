#include<bits/stdc++.h>
using namespace std;

struct student {
    string name;
    int age;
    int roll;
};

int main() {
   int n;
   cin>>n;

   for(int i=0; i<n; i++){
    for(int j=n; j>=0; j--){
        cout<<"*";
    }
   }
   
   
   return 0;

}