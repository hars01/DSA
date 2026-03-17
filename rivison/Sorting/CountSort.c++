#include<bits/stdc++.h>
using namespace std;

void takeArray(vector<int>& arr){
     string s;
    //  cin.ignore();
     getline(cin, s);

     stringstream ss(s);
     int val;
     while(ss>>val){
       arr.push_back(val);
     }
}

void countSort(vector<int>& arr, vector<int>& res){
    if(arr.empty()) return;
     int maxN=0;
     for(int i=0; i<arr.size(); i++){
        maxN=max(maxN, arr[i]);
     }
     
     vector<int> crnt(maxN+1, 0);
     for(int i=0; i<arr.size(); i++){
        crnt[arr[i]]++;
     }

     for(int i=1; i<=maxN; i++){
         crnt[i]+=crnt[i-1];
     }
     
     for(int i=0; i<arr.size(); i++){
         res[crnt[arr[i]]-1]=arr[i];
         crnt[arr[i]]--;
     }
}

void printArray(vector<int> arr){
   for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
   }
   cout<<endl;
}



int main(){
   vector<int> arr;
   takeArray(arr);
   printArray(arr);
   
   vector<int> res(arr.size());
   countSort(arr, res);
   
   printArray(res);
return 0;
}
   