#include<bits/stdc++.h>
using namespace std;

class Solution { 
public:   
    //Union of Two Arrays (Brute Force Approach)
    //Time Complexity: O(n + m)
    //Space Complexity: O(n + m)
    vector<int> unionOfTwoArray(vector<int>& arr1, vector<int>& arr2) {
        // unordered_set<int> unionSet; // If sorted order is not needed, store element of array like unsorted manner
        set<int> unionSet; // If sorted order is needed, store element of array like sorted manner

        for(int num : arr1) {
            unionSet.insert(num);
        }
        for(int num : arr2) {
            unionSet.insert(num);
        }
        // return vector<int>(unionSet.begin(), unionSet.end());
                          //OR
        vector<int> result;
        for(int num : unionSet) {
            result.push_back(num);
        }
        return result;
    }


    //Optimal Approach
    //Time Complexity: O(n + m)
    //Space Complexity: O(1)
    vector<int> unionOfTwoArray2(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        int i = 0, j = 0;
        int n = arr1.size();
        int m = arr2.size();

        while(i < n && j < m) {
            if(arr1[i] < arr2[j]) {
                if(result.empty() || result.back() != arr1[i]) { // To avoid duplicates
                    result.push_back(arr1[i]); // Add element from first array
                }
                i++;   // Move pointer in first array
            } else if(arr1[i] > arr2[j]) {
                if(result.empty() || result.back() != arr2[j]) {
                    result.push_back(arr2[j]);
                }
                j++;
            } else { // When both elements are equal
                if(result.empty() || result.back() != arr1[i]) { // or arr2[j], both are same here
                    result.push_back(arr1[i]);
                }
                i++;
                j++;
            }
        }

        while(i < n) {
            if(result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
        }

        while(j < m) {
            if(result.empty() || result.back() != arr2[j]) {
                result.push_back(arr2[j]);
            }
            j++;
        }

        return result;
    }
};


int main() {
    Solution sol;
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    cout << "Enter elements of first array: ";
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    cout << "Enter size of second array: ";
    cin >> n2;
    cout << "Enter elements of second array: ";
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }
    cout << endl;

    // Since the union function is not implemented, we will just print the input arrays
    cout << "First Array: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Second Array: ";
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;
    

    vector<int> unionArray = sol.unionOfTwoArray(arr1, arr2);
    cout << "Union of Two Arrays: ";        
    for (int num : unionArray) {
        cout << num << " ";
    }

    return 0;
}