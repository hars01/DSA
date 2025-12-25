#include<bits/stdc++.h>
using namespace std;


// Approach using Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)
int findNubers(vector<int> arr){
    int n=arr.size();
    unordered_map<int, int> mp;

    for(auto num: arr){
        mp[num]++;
    }

    for(auto it: mp){
        if(it.second==1){
            return it.first;
            break;
        }
    }

    return -1;
}


// Optimized approach using XOR
// Time Complexity: O(n)
// Space Complexity: O(1)
int findNubersXOR(vector<int> arr){
    int result = 0;
    for(auto num: arr){
        result ^= num;
    }
    return result;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int result = findNubers(arr);
    if(result != -1){
        cout<<"The number that appears only once is: "<<result<<endl;
    } else {
        cout<<"No number appears only once."<<endl;
    }

    return 0;
}