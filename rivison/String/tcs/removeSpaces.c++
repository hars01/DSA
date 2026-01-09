#include <iostream>
using namespace std;

string removeSpaces(string s){
    int cnt=0;
    
    for(int i=0; i<s.length(); i++){
        if(s[i]!=' '){
           s[cnt]=s[i];
           cnt++;
        }
    }
    return s;
}

//usnig character pointer
void removeSpacesPtr(char* s){
    int cnt=0;
    
    for(int i=0; s[i]; i++){
        if(s[i]!=' '){
           s[cnt]=s[i];
           cnt++;
        }
    }
    s[cnt]='\0';
}

    //For character array
int main(){
    char s[] = " Harsh Mishra is always a great guy ";
    removeSpacesPtr(s);
    cout<<s;
    return 0;
}


    //For String Data Structure
// int main(){
//     string s;
//     getline(cin, s);
     
//     string res = removeSpaces(s);
//     cout<<res;
//     return 0;
// }
