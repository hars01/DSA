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

vector<int> spiral(vector<vector<int>> m){
    int sr = 0, sc = 0;
    int er = m.size() - 1;
    int ec = m[0].size() - 1;

    vector<int> res;

    while(sr <= er && sc <= ec){

        // top row
        for(int i = sc; i <= ec; i++)
            res.push_back(m[sr][i]);
        sr++;

        // right column
        for(int i = sr; i <= er; i++)
            res.push_back(m[i][ec]);
        ec--;

        // bottom row
        if(sr <= er){
            for(int i = ec; i >= sc; i--)
                res.push_back(m[er][i]);
            er--;
        }

        // left column
        if(sc <= ec){
            for(int i = er; i >= sr; i--)
                res.push_back(m[i][sc]);
            sc++;
        }
    }
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

    vector<int> res(n*m);
    res=spiral(a);
     
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }

    return 0;
}