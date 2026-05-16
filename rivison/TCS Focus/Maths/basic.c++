#include<bits/stdc++.h>
using namespace std;

void takeArray(vector<int>& arr) {
     string s;
     getline(cin, s);
     
     stringstream ss(s);
     string temp;
     while(getline(ss, temp, ' ')){
         int num=stoi(temp);
         arr.push_back(num);
     }
 }


void printArray(vector<int> arr){
     for(int i=0; i<arr.size(); i++){
             cout<<arr[i]<<" ";
     }
     cout<<endl;
}

void bubble(vector<int>& arr){
    int n=arr.size();
     for(int i=0; i<n-1; i++){
        int a=arr[i];
        for(int j=0; j<n-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
     }

     printArray(arr);
}

void selection(vector<int>& arr){
    int n=arr.size();
     for(int i=0; i<n; i++){
        int midI=i;
        for(int j=i+1; j<n; j++){
            if(arr[midI]>arr[j]){
                midI=j;
            }
            int t=arr[i];
            arr[i]=arr[midI];
            arr[midI]=t;
        }
     }

     printArray(arr);
}

void insertion(vector<int>& arr){
    int n=arr.size();
     for(int i=1; i<n; i++){
        for(int j=i; j>0; j--){
            if(arr[j-1]>arr[j]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
            else {
            break;
            }
        }
     }

     printArray(arr);
}



  
void moveZero(vector<int>& arr){
     int j=0;
     for(int i=0; i<arr.size(); i++){
         if(arr[i]!=0)
          arr[j++]=arr[i];
     }
     
     for(int i=j+1; j<arr.size(); j++){
         arr[j++]=0;
     }
     
     printArray(arr);

}


int main() {
   vector<int> arr;
   takeArray(arr);
   printArray(arr);
   
   insertion(arr);
//    moveZero(arr);
}