#include<bits/stdc++.h>
using namespace std;    



int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    return total - sum;
}

int missingNumberXOR(vector<int>& nums) {
    int n = nums.size();
    int xorFull = 0;
    int xorArray = 0;

    for (int i = 0; i <= n; i++) {
        xorFull ^= i;
    }

    for (int num : nums) {
        xorArray ^= num;
    }

    return xorFull ^ xorArray;
}


int main() {
    vector<int> nums = {3, 0, 1};
    cout << "Missing Number (Sum Method): " << missingNumber(nums) << endl;
    cout << "Missing Number (XOR Method): " << missingNumberXOR(nums) << endl;
    return 0;
}