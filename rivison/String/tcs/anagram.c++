#include <algorithm>
#include <iostream>
#include<unordered_map>
using namespace std;

//Using Sorting 
bool areAnagrams(string &s1, string &s2) {
    
    if (s1.length() != s2.length()) 
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
     return (s1 == s2);
}

// using Map
bool areAnagramsMap(string &s1, string &s2) {
    
    if(s1.size() != s2.size()){
        return false;
    }
    unordered_map<char, int> charCount;

    for(char ch: s1) 
    	charCount[ch] += 1;
    
    for(char ch: s2) 
    	charCount[ch] -= 1;
    
    for (auto& pair : charCount) {
        if (pair.second != 0) {
            return false;
        }
    }
    
    return true;
}


int main() {
    
    string s1 = "geeks";
    string s2 = "kseeg";
    
	if(areAnagrams(s1, s2)){
	    cout << "true" << endl;
	} 
	else{
	    cout << "false" << endl;
	}

    return 0;
}