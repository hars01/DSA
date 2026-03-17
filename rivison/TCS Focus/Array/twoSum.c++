#include<bits/stdc++.h>
using namespace std;

void TakeArray(vector<int>& arr){
   string s;
   getline(cin, s);

   if(s[0]=='[' && s[s.size()-1]==']'){
           s=s.substr(1, s.size()-2);
   }

   stringstream ss(s);
   int num;
   while(ss>>num){
         arr.push_back(num);
   }

//    string temp;
//    while(getline(ss, temp, ',')){
//      int val=stoi(temp);
//      arr.push_back(val);
//    }
   
}

vector<int> TwoSum(vector<int> arr, int t){
     vector<int> res;

      for(int i=0; i<arr.size(); i++){
          for(int j=i+1; j<arr.size(); j++){
             if(arr[i]+arr[j]==t)
             {
                res.push_back(i);
                res.push_back(j);
             }
           }
       }
      return res;
}

void PrintArray(vector<int> arr){
     for(int i=0; i<arr.size(); i++){
             cout<<arr[i]<<" ";
     }
     cout<<endl;
}


int main(){
    vector<int> arr;
    TakeArray(arr);
    PrintArray(arr);

    int t;
    cin>>t;
    vector<int> res = TwoSum(arr, t);
    PrintArray(res);

    return 0; 
}