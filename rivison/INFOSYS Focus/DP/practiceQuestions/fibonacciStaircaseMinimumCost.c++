// A staircase contains N steps, numbered from 1 to N.
// You start at step 1 and want to reach step N.
// From any step, you may jump only by a Fibonacci number of steps. In other words, if you are currently at step i, you may move to:
// i + 1
// i + 2
// i + 3
// i + 5
// i + 8...
// where the jump length must be a Fibonacci number (1, 2, 3, 5, 8, 13, ...) and the destination step must not exceed N.
// The cost of making a jump of length k is:

// Cost=A+B×k

// where:
// A is the fixed cost per jump.
// B is the variable cost per unit jump length.
// k is the Fibonacci jump length.
// Your task is to determine the minimum total cost required to reach step N from step 1.

// Input
// 6 4 3
// Output
// 19
// Explanation
// Possible paths:
// 1 → 6 (jump = 5)
// Cost = 4 + 3 × 5 = 19

// 1 → 4 → 6
// Cost = (4 + 3 × 3) + (4 + 3 × 2) = 13 + 10 = 23

// 1 → 2 → 4 → 6
// Cost = 7 + 10 + 10 = 27

// The minimum cost is 19.


#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        int memoization(int n, int a, int b){
            vector<int> fib={1,2}; //the first two Fibonacci numbers, by using them we generate the rest of the Fibonacci numbers
            vector<int> dp(n+1, INT_MAX); //dp[i] will store the minimum cost to reach step i
            dp[1]=0; //the cost to reach step 1 is 0


            for(int i=2; i<=n; i++){

                for(int jumps: fib){
                    int next=i+jumps;

                    if(next>n){
                        break;
                    }

                    dp[next]=min(dp[next], dp[i]+a+b*jumps);
                }
            }

            if(dp[n]==INT_MAX)
                return -1; //if we can't reach step n, we print -1
            else
                return dp[n]; //otherwise, we print the minimum cost to reach step n
        }

    public:
            int minCost(int n, int a, int b){
                return memoization(n, a, b);
            }
};

int main(){
    int n, A, B;
    cin>>n>>A>>B;
    Solution obj;
    cout<<obj.minCost(n, A, B)<<endl;

}