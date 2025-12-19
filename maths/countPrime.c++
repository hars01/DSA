#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    // Time Complexity: O(n√n)
    int countPrimes(int n) {
        int Ocnt=0;
        if(n<=2){
            return 0;
        }
        for(int i=1; i<n; i++){
            int cnt = 0;
            for(int j=1; j<=i; j++){
                if(i%j==0)
                cnt++;
            }
            if(cnt==2)
                Ocnt++;         
        }
        return Ocnt;
    }


    // Time Complexity: O(n log log n)
    int countPrimesEfficient(int n) {
    if(n<=2)
        return 0;

        vector<int> prime(n, true);

        prime[0]=false;
        prime[1]=false;


        for(int i=2; i*i<n; i++){
            if(prime[i]){
                for(int j=i*i; j<n; j+=i)
                prime[j]=false;
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) 
            count++;
        }

        return count;
    }

};


int main(){
    Solution obj;
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Number of primes less than "<<n<<" is: "<<obj.countPrimes(n)<<endl;
    cout<<"Number of primes less than "<<n<<" is: "<<obj.countPrimesEfficient(n);

    return 0;
}