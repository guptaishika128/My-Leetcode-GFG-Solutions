//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
         int maxSum = INT_MIN;
        
        for(int i=0; i<R; i++){
            
            vector<int> row(C,0);
            for(int r=i; r<R; r++){
                for(int j=0; j<C; j++){
                    row[j] += M[r][j];
                }
                
                //kadane's algo on row array
                int sum = 0;
                for(int j=0; j<C; j++){
                    sum += row[j];
                    maxSum = max(sum,maxSum);
                    if(sum < 0){
                        sum = 0;
                    }
                }
            }
        }
        
        return maxSum;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends