#include<bits/stdc++.h>
using namespace std;

bool solution(string s, string q)
{
        int i=0, j=0;
        while(i<s.size() && j<q.size())
        {
            if(s[i]!=q[j])
            {
                if(q[j]!='*' && q[j]!='?')
                return false;
                i++;
                j++;
            }
            i++;
            j++;
        }
        return true;
}
int maing(){
    string s;
    getline(cin, s);
    
    string t;
    // cin.ignore();
    getline(cin, t);

    cout<<solution(s, t);

}