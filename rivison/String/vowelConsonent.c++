#include <bits/stdc++.h>
using namespace std;

string transformString(const string &s) {
    // vowel mapping given by user: a->e, e->o, o->i, i->u, u->a
    unordered_map<char,char> vowelMap = {
        {'a','e'}, {'e','i'}, {'i','o'}, {'o','u'}, {'u','a'}
    };

    string out;
    out.reserve(s.size());

    for (char ch : s) {
        // assume input contains only lowercase letters a-z
        if (vowelMap.find(ch) != vowelMap.end()) {
            out.push_back(vowelMap[ch]);            // map vowel
        } else {
            // previous alphabet letter with wrap: 'a' -> 'z'
            char prev = (ch - 1);
            out.push_back(prev);
        }
    }

    return out;
}

int main() {
    string input;
    // example: read a single word/string
    if (!(cin >> input)) return 0;

    cout << transformString(input) << '\n';
    return 0;
}
