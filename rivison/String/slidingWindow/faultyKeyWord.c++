#include<bits/stdc++.h>
using namespace std;        

void Push_back(string &s, char c){
    s+=c; // Append character c to the end of string s
}

void Push_Back(vector<int> &v, int x){
    //integer x to the end of vector v without using any predefined and stl function

}

class Solution {
public:
    string finalString(string s) {
        string res="";
        for(char c: s){
            if(c=='i'){
            reverse(res.begin(), res.end());
            }
            else {
            Push_back(res, c);
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    string s;
    cin>>s;

    vector<int> ans;
    Push_Back(ans, 1);
    cout<<sol.finalString(s)<<endl;
    return 0;
}