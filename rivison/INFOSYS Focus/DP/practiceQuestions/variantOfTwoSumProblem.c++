// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
//     public:
//        int variantOfTwoSumProblem(int n, int D, int M, vector<int> arr){
//             map<pair<int, int>,int> mp;

//             int result = 0;

//             for(int i=0; i<n; i++){
//                 int remM=((arr[i]%M)+M)%M;
//                 int remD=((arr[i]%D)+D)%D;

//                 int need = (D-remD)%D;
//                 mp[{remM, need}]++;
//                 result += mp[{remM, need}];
//             }

//             return result;
//        }
// };

// int main(){
//     int n, D, M;
//     cout<<"Enter size, D and M : "<<endl;
//     cin>>n>>D>>M;

//     vector<int> arr(n);
//     cout<<"Enter array elements : "<<endl;
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }

//     Solution sol;
//     cout<<"Result : "<<sol.variantOfTwoSumProblem(n, D, M, arr)<<endl;

// }


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int variantOfTwoSumProblem(int n,int D,int M,vector<int>& arr){

        map<pair<int,int>,int> mp;
        int ans=0;

        for(int x:arr){

            int remM=((x%M)+M)%M;
            int remD=((x%D)+D)%D;

            int need=(D-remD)%D;

            // Count previous valid elements
            ans += mp[{remM,need}];

            // Store current element
            mp[{remM,remD}]++;
        }

        return ans;
    }
};

int main(){

    int n,D,M;
    cin>>n>>D>>M;

    vector<int> arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    Solution sol;

    cout<<sol.variantOfTwoSumProblem(n,D,M,arr);

}