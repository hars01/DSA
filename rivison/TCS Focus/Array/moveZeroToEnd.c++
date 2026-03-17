#include<bits/stdc++.h>
using namespace std;

void TakeArray(vector<int>& arr){
   string s;
   getline(cin, s);
   stringstream ss(s);

   string temp;
   while(getline(ss, temp, ',')){
     int val=stoi(temp);
     arr.push_back(val);
   }
}
 

void moveZeroToEnd(vector<int>& arr, vector<int>& res) {
    int j=0;
     for(int i=0; i<arr.size(); i++) {
        if(arr[i]!=0){
            res[j++]=arr[i];
        }
     }
}

void PrintArray( vector<int> arr){
    int n=arr.size();
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main() {
vector<int> arr;
TakeArray(arr);
vector<int> res(arr.size(), 0);

PrintArray(arr);
moveZeroToEnd(arr, res);
PrintArray(res);

return 0;
}