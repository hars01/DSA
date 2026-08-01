#include<bits/stdc++.h>
using namespace std;


// knapsack where hole values of weight(wt) will be allows

class Solution {
   public:
      int knapsack(vector<int> wt, vector<int> pt, int capacity){
        int n=wt.size();
        vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));


        for(int i=1; i<n+1; i++){
            for(int w=1; w<capacity+1; w++){
                 if(wt[i-1]<=w){
                    dp[i][w]=max(dp[i-1][w], pt[i-1]+dp[i-1][w-wt[i-1]]);
                 } else {
                    dp[i][w]=dp[i-1][w];
                 }
            }
        }

        return dp[n][capacity];
      }
};


int main(){
    int n;
    cin>>n;
    vector<int> wt(n);
    vector<int> pt(n);

    cout<<"Weight"<<endl;
    for(int i=0; i<n; i++){
        cin>>wt[i];
    }
    

    cout<<"Values"<<endl;
    for(int i=0; i<n; i++){
        cin>>pt[i];
    }


    cout<<"Capacity"<<endl;
    int capacity;
    cin>>capacity;


    Solution sol;
    int res=0;
    res=sol.knapsack(wt, pt, capacity);

    cout<<"Result : "<<res;

}