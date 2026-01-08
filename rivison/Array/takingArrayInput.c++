#include<bits/stdc++.h>
using namespace std;

 vector<int> normally(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
    cin>>arr[i];
    
    return arr;
 }

 vector<int> withoutAnySize(){
    string s;
    cin.ignore();
    getline(cin, s);
    stringstream ss(s);

    vector<int> arr;

    int num;
    while(ss>>num){
      arr.push_back(num);
    }
    return arr;
 }


 vector<int> withSpacing(){
    string s;
    getline(cin, s);
    stringstream ss(s);

    vector<int> arr;

    string temp;
    while(getline(ss, temp, ' ')){
      int num=stoi(temp);
      arr.push_back(num);
    }
    return arr;
 }

  vector<int> withComma(){
    string s;
    getline(cin, s);
    stringstream ss(s);

    vector<int> arr;

    string temp;
    while(getline(ss, temp, ',')){
      int num=stoi(temp);
      arr.push_back(num);
    }
    return arr;
 }

 vector<int> withBracket(){
    string s;
    getline(cin, s);
    vector<int> arr;

    if(s.front() == '[' && s.back() == ']')
    s=s.substr(1, s.length()-2);

    stringstream ss(s);
    string taken;

    while(getline(ss, taken, ',')){
        int num=stoi(taken);
        arr.push_back(num);
    }
    return arr;
 }

void printArray( vector<int> arr){
    int n=arr.size();
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    cout<<"Input of first type ofarray Normally  :-"<<endl;
    vector<int> res1=normally();
    cout<<endl<<"Input of second type of array Without any Prior Size of Array  :-"<<endl;
    vector<int> res2=withoutAnySize();
    cout<<endl<<"Input of third type of array With Spacing in Between the elements(1 2 3 4 5) of Array  :-"<<endl;
    vector<int> res3=withSpacing();
    cout<<endl<<"Input of Fourth type of array With Comma in Between the elements(1,2,3,4,5) of Array  :-"<<endl;
    vector<int> res4=withComma();
    cout<<endl<<"Input of Fifth type of array With Brackets (like [], {}, () ) in start and end with the elements([1 2 3 4 5]) of Array  :-"<<endl;
    vector<int> res5=withBracket();


    cout<<endl<<"Array-1 :"<<endl;
    printArray(res1);
    cout<<endl<<"Array-2 :"<<endl;
    printArray(res2);
    cout<<endl<<"Array-3 :"<<endl;
    printArray(res3);
    cout<<endl<<"Array-4 :"<<endl;
    printArray(res4);
    cout<<endl<<"Array-5 :"<<endl;
    printArray(res5);
    
    return 0;
}