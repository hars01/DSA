#include<bits/stdc++.h>
using namespace std;


class Solution {
  private: 
    int recursion(int day, int last, vector<vector<int>> &points){
            if(day==0){
                int maxi=0;
                for(int task=0; task<3; task++){
                    if(task!=last){
                        maxi=max(maxi, points[day][task]);
                    }
                }
                return maxi;
            }


            int maxi=0;
            for(int task=0; task<3; task++){
                if(task!=last){
                    int point=points[day][task]+recursion(day-1, task, points);
                    maxi=max(maxi, point);
                }
            }

            return maxi;
        }
        
        int memoization(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
            
            
            if(day==0){
                int maxi=0;
                for(int task=0; task<3; task++){
                    if(task!=last){
                        maxi=max(maxi, points[day][task]);
                    }
                }
                return maxi;
            }

            if(dp[day][last]!=-1){
                return dp[day][last];
            }

            int maxi=0;
            for(int task=0; task<3; task++){
                if(task!=last){
                    int point=points[day][task]+memoization(day-1, task, points, dp);
                    maxi=max(maxi, point);
                }
            }

            return dp[day][last]=maxi;
        }
        
  public:
    int maximumPoints(int n, vector<vector<int>>& mat) {
        
        
        // int res=recursion(n-1, 3, mat);
        
        vector<vector<int>> dp(n, vector<int>(4, -1));
        int res=memoization(n-1, 3, mat, dp);
        return res;
    }
};




int main(){
    int day;
    cout<<"Number of Days : ";
    cin>>day;

    vector<vector<int>> points(day, vector<int>(3));
    for(int i=0; i<day; i++){
        for(int j=0; j<3; j++){
            cin>>points[i][j];
        }
    }

    Solution sol;
    int res=sol.maximumPoints(day, points);
    cout<<res<<endl;

}