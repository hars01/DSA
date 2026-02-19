#include<bits/stdc++.h>
using namespace std;


int knapsack(vector<int> wt, vector<int> profit, int n, int cap) {
       vector<int> res;
       if(n==0 || cap==0)
       return 0;
    
       int pick=0;

       if(wt[n-1]<=cap)
       pick=profit[n-1]+knapsack(wt, profit, n-1, cap-wt[n-1]);

       int notPick = knapsack(wt, profit, n - 1, cap);
     
       return max(pick, notPick);
}

int knapsackRec(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    return knapsack(val, wt, n, W);
}

int main(){
    int n;
    cin>> n;
    vector<int> wt(n), profit(n);
    for(int i=0; i<n; i++){
    cout<<"Weight of "<<i<<" :- ";
    cin>>wt[i];
    cout<<"Profit of "<<i<<" :- ";
    cin>>profit[i];
    }

    int cap;
    cout<<"Capacity : ";
    cin>>cap;

    cout<<"Weights : ";
    for(int i=0; i<n; i++){
    cout<<wt[i]<<" ";
    }
    cout<<endl;
    cout<<"Profits : ";
    for(int i=0; i<n; i++){
    cout<<profit[i]<<" ";
    }

    int res=knapsackRec(cap, profit, wt);

    cout<<endl<<res;
}