#include <bits/stdc++.h>
using namespace std;

bool solution(string s, string q) {
    int n = s.size(), m = q.size();
    int i = 0, j = 0;
    int startIndex = -1, match = 0;

    while (i < n) {
        // Case 1: Characters match or pattern has '?'
        if (j < m && (s[i] == q[j] || q[j] == '?')) {
            i++;
            j++;
        }
        // Case 2: Pattern has '*', mark the position and try matching 0 characters first
        else if (j < m && q[j] == '*') {
            startIndex = j;
            match = i;
            j++;
        }
        // Case 3: Mismatch occurs, backtrack to the last '*' seen
        else if (startIndex != -1) {
            j = startIndex + 1;
            match++;
            i = match;
        }
        // Case 4: No match and no '*' to backtrack to
        else {
            return false;
        }
    }

    // Check for remaining '*' in pattern (they can match empty strings)
    while (j < m && q[j] == '*') {
        j++;
    }

    return j == m;
}

int main() {
    string s = "hars";
    string t = "ha*sh";

    if (solution(s, t)) 
        cout << "Match Found" << endl;
    else 
        cout << "No Match" << endl;

    return 0;
}