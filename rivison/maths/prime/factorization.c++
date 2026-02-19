#include<bits/stdc++.h>
using namespace std;

void primeFactorization(int num) {
    // // 1. Handle the factor 2
    // while (num % 2 == 0) {
    //     cout << 2 << " ";
    //     num /= 2;
    // }

    // 2. Handle odd factors from 3 to sqrt(num)
    for (int i = 2; i * i <= num; i++) {
        while (num % i == 0) {
            cout << i << " ";
            num /= i;
        }
    }

    // 3. If num is still > 2, the remaining num is a prime number
    if (num > 2) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    primeFactorization(n);
    return 0;
}