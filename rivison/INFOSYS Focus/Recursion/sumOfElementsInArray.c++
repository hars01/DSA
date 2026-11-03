#include<bits/stdc++.h>
using namespace std;

// class Solution {
//     public: 
        
// };


void sumofelemnts(int arr[], int i, int n, int sum){
        if(i==n){
            cout<<sum<<endl;
            return;
        }


        sum+=arr[i];

        sumofelemnts(arr, i+1, n, sum);

}


int main(){
    int n=5;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }


    sumofelemnts(arr, 0, n, 0);

    return 0;
}