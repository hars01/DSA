#include <iostream>
using namespace std;

// Recursive Binary Search Function
int binarySearch(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid; 
        }
        if (arr[mid] > key) {
            return binarySearch(arr, left, mid - 1, key);
        }
        return binarySearch(arr, mid + 1, right, key);
    }
    return -1; 
}

// Recursive Linear Search Function
int linearSearch(int arr[], int size, int key, int index = 0) {
    if (index == size) {
        return -1; 
    }
    if (arr[index] == key) {
        return index; 
    }
    return linearSearch(arr, size, key, index + 1); 
}

int main() {
    int arr[] = {2, 5, 8, 10, 15, 18, 25}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the element to search: ";
    cin >> key;

    // Binary Search Test
    int binaryResult = binarySearch(arr, 0, n - 1, key);
    if (binaryResult != -1) {
        cout << "Binary Search: Element found at index " << binaryResult << endl;
    } else {
        cout << "Binary Search: Element not found" << endl;
    }

    // Linear Search Test
    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1) {
        cout << "Linear Search: Element found at index " << linearResult << endl;
    } else {
        cout << "Linear Search: Element not found" << endl;
    }

    return 0;
}
