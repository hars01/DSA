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

int diagonalSum(vector<vector<int>>a, int n, int m){
    int sum =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==j)
            sum+=a[i][j];
            else if(j==n-i-1){
                sum+=a[i][j];
            }
        }
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>>a=takeInput(n, m);
    int res=diagonalSum(a, n, m);
    cout<<res;
    return 0;
}
