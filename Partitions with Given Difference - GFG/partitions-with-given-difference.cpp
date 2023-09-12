//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int sub( vector<int>& arr,int s1,int n)
    {
        int dp[n+1][s1+1];
        memset(dp,0,sizeof(dp));
        int m=1000000000+7;
        for(int i=0; i<=n;i++)
        {
            for(int j=0; j<=s1; j++)
            {
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
                
        for(int i=1; i<=n;i++)
        {
            for(int j=0; j<=s1; j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j]=(dp[i-1][j-arr[i-1]]+dp[i-1][j])%m;
                }
                else
                {
                    dp[i][j]=dp[i-1][j]%m;
                }
            }
        }
        return dp[n][s1]%m;
        
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        const int MOD = 1e9 + 7;
       int totSum = 0;
    for(int i=0;i<n;i++){
        totSum += arr[i];
    }
    if(totSum-d < 0 || (totSum-d)%2!=0){
        return false;
    }
    int k = (totSum-d)/2;

    vector<vector<int>>dp(n,vector<int>(k+1,0));

    if(arr[0] == 0){
        dp[0][0] = 2;
    }
    else{
        dp[0][0] = 1;
    }

    if(arr[0]!= 0  && arr[0]<=k)
        dp[0][arr[0]] = 1;

    for(int ind = 1;ind<n;ind++){
        for(int target = 0;target<=k;target++){
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= (notTaken + taken)%MOD;

        }
    }
    return dp[n-1][k]%MOD;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends