#include<bits/stdc++.h>
using namespace std;

void takeArray(vector<int>& res) {
     string s;
     cin.ignore();
     getline(cin, s);
     
     stringstream ss(s);

     char c;
     while(ss>>c){
           res.push_back(c);
     }
}

int BuySellStock(vector<int> nums){
      int n=nums.size();
      int mini=nums[0], profit=0;
      for(int i=1; i<n; i++){
          int cost=nums[i]-mini;
          profit=max(profit, cost);
          mini=min(mini, nums[i]);
      }
      
   return profit;
}

int main() {
    vector<int> arr;
    takeArray(arr);

    int res=BuySellStock(arr);
    cout<<res;
    return 0;
}
     



    