#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Brute Force Approach
    //Time Complexity: O(n+k)
    //Space Complexity: O(k)
    void rotateAtK(vector<int>& arr, int k) {
        vector<int> temp;
        int n = arr.size();
        int rotateIndex = k % n; // Handle cases where k >= n
        for(int i=0; i<k; i++){
            temp.push_back(arr[i]);
        }
        for(int i=rotateIndex; i<n; i++){
            arr[i - rotateIndex] = arr[i]; // Shift elements to the front
        }
        for(int i=0; i<k; i++){
            arr[n - rotateIndex + i] = temp[i]; // Place the saved elements at the end
        }
    }

    //Optimal Approach
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    void rotateAtK2(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n;
        reverse(arr.begin(), arr.begin() + k); // Reverse first k elements
        reverse(arr.begin() + k, arr.end()); // Reverse remaining n-k elements
        reverse(arr.begin(), arr.end()); // Reverse the whole array
    }
};


int main() {
    Solution sol;
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elements of array: ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<endl;

    int k;
    cout << "Enter rotation index k: ";
    cin >> k;

    sol.rotateAtK2(arr, k);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}

