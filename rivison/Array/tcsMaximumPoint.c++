#include<bits/stdc++.h>
using namespace std;


vector<int> takeArray(){
     string arr;
     cin.ignore();
     getline(cin, arr);
     stringstream ss(arr);
     vector<int> nums;

     int num;
     while(ss>>num){
         nums.push_back(num);
     }
     return nums;
}


int maxAnswer(vector<int> arr){
     int odd=0;
     int even=0;
     
     for(int i=0; i<arr.size(); i++){
             if((i+1)%2!=0)
             odd+=arr[i];
             else
             even+=arr[i];
     }

     int m=max(odd, even);
     return m;
}

int main() {
   
   vector<int> nums = takeArray();
   
   int res=maxAnswer(nums);
   cout<<res;
      

   return 0;
}

