// Input: string1 = "occurrence" string2 = "car"
// Output: "ouene"
// Explanation: After removing characters (c, a, r) from string1 we get "ouene".

#include <bits/stdc++.h>
using namespace std;

string removeChars(string string1, string string2) {
       //we extract every character of string string 2
         for(auto i:string2)
         {
           while(find(string1.begin(),string1.end(),i)!=string1.end())
            {
                auto itr = find(string1.begin(),string1.end(),i);
               //if char exit we simply remove that char
                string1.erase(itr);
            }
         }
        return string1;
    }

    
int main()
{
        string string1,string2;
        string1="geeksforgeeks";
        string2="mask";
        cout<<  removeChars(string1,string2)<<endl;;
       return 0;
}