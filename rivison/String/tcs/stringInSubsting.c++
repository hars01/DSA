// Input: txt = "geeksforgeeks", pat = "eks"
// Output: 2
// Explanation: String "eks" is present at index 2 and 9, so 2 is the smallest index.

#include<bits/stdc++.h>
using namespace std;


int findSubstring(string txt, string pat){
    int n = txt.length();
    int m = pat.length();

    for(int i=0; i<=n-m; i++){
        int j;
        for(j=0; j<m; j++){
            // Mismatch found
            if (txt[i + j] != pat[j]) {
              break;
            }
        }

        if (j == m) {
           return i;
        }
    }
    // No match found
    return -1;
}


int main() {
    string txt = "geeksforgeeks";
    string pat = "eks";
    cout << findSubstring(txt, pat);

    return 0;
}