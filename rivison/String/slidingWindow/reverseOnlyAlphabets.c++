// Leetcode Problem Link: https://leetcode.com/problems/reverse-only-letters/
// description: Given a string s, reverse the string according to the following rules:
// example: Input: s = "ab-cd" Output: "dc-ba"
#include<bits/stdc++.h>
using namespace std;

bool isAlpha(char c){
   if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        return true;
    return false;
}

int Size(string s){
    int count=0;
    // for(int i=0;s[i]!='\0';i++){
    //     count++;
    // }
           //  OR
    for(char c:s){
        count++;
    }
    return count;
}

// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(1)
// Two Pointer Approach
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=Size(s)-1;

        while(i<j){

            if(!isAlpha(s[i])){
            i++;
            }
            else if(!isAlpha(s[j])){
            j--;
            }
            else {
            char temp= s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
            }
        }

        return s;
    }
};


int main(){
    Solution obj;
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<obj.reverseOnlyLetters(s);
    return 0;
}