class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        vector<int> ans(n+1, 1);
        for(int i = 1; i <= n; i++)
            for(int j = i-1; j > 0; j--)
                ans[j] += ans[j-1];
        return ans;
      
    }
};