#include<bits/stdc++.h>
using namespace std;


// Function to reverse an integer
// Time Complexity: O(log10(n)) where n is the input integer
// Space Complexity: O(1)
class Solution {
public:
    int reverse(int x) {
       int r=0; // to store the reversed integer
       while(x)
       {
        r=r*10+x%10; // store the last digit of x to r
        x=x/10; // remove the last digit from x
       }
       if(r>INT_MAX || r<INT_MIN) // check for overflow
       return 0;
       return r; 
    }
};

// Dry run
// Input: x = -123
// Step 1: r = 0 * 10 + (-123 % 10) = 0 + (-3) = -3, x = -123 / 10 = -12
// Step 2: r = -3 * 10 + (-12 % 10) = -30 + (-2) = -32, x = -12 / 10 = -1
// Step 3: r = -32 * 10 + (-1 % 10) = -320 + (-1) = -321, x = -1 / 10 = 0
// Output: r=-321 

int main()
{
    Solution obj;
    int x;
    cin>>x;
    cout<<obj.reverse(x);
    return 0;
}