// In short description: The vehicles with the odd last digit in the registration number will be allowed on roads on odd dates and those with even last digit will on even dates.
//  Given an integer array a[], contains the last digit of the registration number of N vehicles traveling on date D(a positive integer). The task is to calculate the total fine collected by the traffic police department from the vehicles violating the rules.
// Note : For violating the rule, vehicles would be fined as X Rs.

#include<bits/stdc++.h>

using namespace std;

class Solution {
    public: 
         int findPenality(vector<int> &a, int n, int d, int x) {
            int totalFine=0;

            for(int i=0; i<n; i++){
                if(d%2==0 && a[i]%2!=0){
                    totalFine=totalFine+x;
                }
                else if(d%2!=0 && a[i]%2==0){
                    totalFine=totalFine+x;
                }
            }

            
            return totalFine;
         }
};


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int d;
    cin>>d;

    int x;
    cin>>x;

    Solution obj;
    int res=obj.findPenality(a, n, d, x);

    cout<<res<<endl;
    return 0;
}