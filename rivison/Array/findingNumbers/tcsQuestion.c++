//Input : 99 -> Value of N, 3  -> Value of R
// Output :9  -> Possible ways to fill the cistern.
// Explanation: the number N=99
// Sum of the digits N: 9+9 = 18
// Repeat step 2 ‘R’ times i.e. 3 tims  (9+9)+(9+9)+(9+9) = 18+18+18 =54
// Add digits of 54 as we need a single digit 5+4
// Hence , the output is 9.

#include<bits/stdc++.h>
using namespace std;

vector<int> convertInArray(int n){
    vector<int> dig;
    while(n>0){
        dig.push_back(n%10);
        n=n/10;
    }
    return dig;
}

int findArraySum(vector<int> &arr){
    int sum=0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
    }
    return sum;
}

class Solution {
    public: 
         int findingNumbers(int n, int r){
            vector<int> digits=convertInArray(n);
            int sum=findArraySum(digits);
            for(int i=0; i<r; i++){
                sum += sum;
            }
            vector<int> finalDigits=convertInArray(sum);
            int finalSum=findArraySum(finalDigits);
            return finalSum;
         }
};

int main(){
    int n;
    cin>>n;

    int r;
    cin>>r;

    Solution obj;
    int res=obj.findingNumbers(n, r);

    cout<<res<<endl;
    return 0;
}