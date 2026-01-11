#include<bits/stdc++.h>
using namespace std;

vector<int> takeInput(string s){
        stringstream ss(s);
        int num;
        vector<int> res;
        while(ss>>num){
            res.push_back(num);
        } 
        return res;
}

vector<int> bSort(vector<int> arr){
    int n=arr.size();
    for(int i=0; i<n-1; i++){
        // bool swaped=false;
        for(int j=0; j<n-1; j++){
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

                // swaped=true;
            }
        }
        // if(swaped==false)
        // break;
    }
    return arr;
}

void print(vector<int> arr){
    int n=arr.size();

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    string s;
    getline(cin, s);

    vector<int> nums=takeInput(s);
    print(nums);
    vector<int> res=bSort(nums);
    print(res);
    return 0;
}