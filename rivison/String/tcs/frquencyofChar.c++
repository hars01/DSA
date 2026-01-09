// Input: s = "geeksforgeeks"
// Output: g2 e4 k2 s2 f1 o1 r1

#include <iostream>
#include<unordered_map>
using namespace std;

string modifyString(string s) {
    unordered_map<char, int> d;
    string res = "";

     for (char i : s) {
        d[i]++;
    }

    // Build the result string with characters 
    // and their frequencies
    for (char i : s) {
        if (d[i] != 0) {
            // append character and frequency
            res += i + to_string(d[i]) + " "; 
            // mark as processed
            d[i] = 0; 
        }
    }

    return res;
}

int main() {
    string s;
    getline(cin, s);

    cout << modifyString(s);
    return 0;
}