#include<bits/stdc++.h>
using namespace std;    

void reverse(vector<int>& arr) {
    int i=0;
    int j=arr.size()-1;
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];        
        arr[j] = temp;
        i++;
        j--;
    }
}


int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elements of array: ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << endl;

    reverse(arr);

    cout << "Reversed array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}