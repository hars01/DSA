// Question : Implement a function to find all possible letter combinations that a given digit string could represent on a phone keypad.
// The mapping of digits to letters is as follows:
// 2 -> "abc"
// 3 -> "def"
// 4 -> "ghi"
// 5 -> "jkl"
// 6 -> "mno"
// 7 -> "pqrs"
// 8 -> "tuv"
// 9 -> "wxyz"
// For example, given the input "23", the output should be ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// keys 2,3,4,5,6,8 each represents 3 letters, at most 3 consecutive presses of these keys can be made.
// keys 7,9 each represents 4 letters, at most 4 consecutive presses of these keys can be made.
// return the total number of possible letter combinations that can be generated from the given digit string.

// Sample Input: "22233"
// Sample Output: 8 


#include <bits/stdc++.h>
using namespace std;


class Solution {
     
            const int mod = 1e9+7;
            vector<int> dp;
   
        int memoization(int i, string &digits) {
            int n=digits.size();

            if(i==n) return 1;
            if(dp[i] != -1) return dp[i]; 

            long long ways=0;
            // char currentDigit = digits[i];

            int limit=(digits[i]=='7'||digits[i]=='9')?4:3;


            for(int j=1; j<=limit; j++) {
                if(i+j > n) break;
                bool valid = true; // check if the next j digits are the same as currentDigit
                
                for(int k=i; k<i+j; k++) {
                    if(digits[k] != digits[i]) {
                        valid = false;
                        break;
                    }
                }
                if(!valid) break;

                ways = (ways + memoization(i+j, digits)) % mod;    
            }

            return dp[i] = ways;
        }

    public:
        int letterCombinations(string digits) {
            if(digits.empty())
            return 0;

            dp.assign(digits.size(),-1);

            return memoization(0,digits);
        }
};


int main()
{
    Solution s;

    string digits;
    cin>>digits;

    cout<<s.letterCombinations(digits);

    return 0;
}