#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
       int findWeidthLeft(int ind, vector<int> heights, int n){
            for(int i=ind; i>=0; i--)  {
               if(heights[i]<heights[ind])
               return i;
            }

            return 0;
       }

       int findWeidthRight(int ind, vector<int> heights, int n){
            for(int i=ind; i<n; i++)  {
               if(heights[i]<heights[ind])
               return i;
            }

             return 0;
       }

    
    public:
      
       int largestArea(vector<int> heights, int n){
            int ans=0;
             for(int i=0; i<n; i++){
                int l=findWeidthLeft(i, heights, n);
                int r=findWeidthRight(i, heights, n);

                    
                int area=heights[i]*(r-l-1);
                ans=max(ans, area);
             }
             return ans;
       }

};


int main() {
    Solution s;

    int n;
    cout<<"Enter size of Hights/Bar in Histoghram : ";
    cin>>n;

    vector<int> heights(n);
    cout<<"Enter "<<n<<" Heights : "<<endl;
    for(int i=0; i<n; i++){
        cin>>heights[i];
    }

    int result = s.largestArea(heights, n);
    cout<<"Maximum Area of Rectangel is : "<<result;
 
    

}