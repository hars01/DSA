#include<bits/stdc++.h>
using namespace std;

class Solution {
        public: 
              void primeFactorization(int num){
                           while(num%2==0){
                                  cout<<2<<" ";
                                  num/=2;
                           }
                           while(num%3==0){
                                  cout<<3<<" ";
                                  num/=3;
                           }
                           for(int i=4; i*i<num; i++)
                           {
                              if(num%i==0){
                                 cout<<i<<" ";
                                 num/=i;
                              }
                           }
                
          }
};
                           

int main() {
    int n;
    cin>>n;
    Solution s;
    s.primeFactorization(n);
    return 0;
}
