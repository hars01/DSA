#include<bits/stdc++.h>
using namespace std;

int Size(const vector<int>& arr) {
    int count = 0;
    for(auto element : arr) {
        count++;
    }
    return count;
}

class ArrayReverser {
    public:
        void reverseArray(vector<int>& arr) {
            int left = 0;
            int right = Size(arr) - 1;

            while(left < right) {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
};

int main() {
    ArrayReverser reverser;
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    reverser.reverseArray(arr);

    cout << "Reversed array: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    reverse(arr.begin(), arr.end());
    cout << "Reversed array using STL: ";   
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}