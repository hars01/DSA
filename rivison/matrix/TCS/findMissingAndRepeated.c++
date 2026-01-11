#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>takeInput(int n, int m){
    // int a[n][m];
    vector<vector<int>>a(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    return a;
}

vector<int> findMissing(vector<vector<int>> m){
         vector<int> res;
         unordered_map<int, int> set;
                   //OR
        //  unordered_set<int> set;

        
         int n=m.size();

         int a=-1, expSum=0, actualSum=0;

         for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                actualSum+=m[i][j];
                if(set.find(m[i][j])!=set.end()){
                    a=m[i][j];
                    res.push_back(a);
                }
                set[m[i][j]]++;     // when use set set.insert(m[i][j])
            }
         }
         expSum=(n*n)*(n*n+1)/2;
         int b=expSum+a-actualSum;
         res.push_back(b);


         return res;
    
}


int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<vector<int>>a;
    a = takeInput(n, m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<int> res;
    res=findMissing(a);
     
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }

    return 0;
}

