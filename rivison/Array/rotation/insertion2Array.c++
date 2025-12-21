#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
           vector<int> insertion(vector<int> a, vector<int> b){
            vector<int> result;
            int n = a.size();
            int m = b.size();
            int i = 0, j = 0;

            while(i<n && j<m){
                if(a[i]<b[j]){
                    i++;
                }
                else if(a[i]>b[j]){
                    j++;
                }
                else {
                    result.push_back(a[i]);
                    i++;
                    j++;
                }
            }

            // // Add remaining elements from a
            // while(i < n){
            //     result.push_back(a[i]);
            //     i++;
            // }

            // // Add remaining elements from b
            // while(j < m){
            //     result.push_back(b[j]);
            //     j++;
            // }

            return result;
           }
};


int main() {
    vector<int> a={2,3,4,5,6,7};
    vector<int> b={1,3,4,6,9};


    Solution sol;
    vector<int> res;
    res=sol.insertion(a, b);

    cout<<"Intersection of two array is: ";
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    
    return 0;
}