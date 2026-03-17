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
 

int secondGreatest(vector<int> arr){
    int n=arr.size();
    
    int maxi=0, jmaxi=0;
    
    for(int i=0; i<n; i++){
        if(arr[i]>maxi){
            jmaxi=maxi;
            maxi=arr[i];
        }
    }

return jmaxi;
}


int secondGreatest2Logic(vector<int> arr){
    int n=arr.size();
    int maxi=0, jmaxi=0;

for(int i=0; i<n; i++){
    maxi=max(maxi, arr[i]);
}

for(int i=0; i<n; i++){
   if(arr[i]>=maxi)
   break;
  jmaxi=max(jmaxi, arr[i]);
}
return jmaxi;
}

void PrintArray(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
vector<int> arr;
TakeArray(arr);
PrintArray(arr);
cout<<secondGreatest2Logic(arr)<<" ";
return 0;
}