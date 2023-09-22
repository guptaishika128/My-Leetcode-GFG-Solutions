class Solution {
public:
    void solve(int col , vector<string>& temp, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal , int n){
        if(col == n){
            ans.push_back(temp);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0){
                temp[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[n-1+col-row] = 1;
                lowerDiagonal[row+col] = 1;
                solve(col+1,temp,ans,leftRow,upperDiagonal,lowerDiagonal,n);
                temp[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[n-1+col-row] = 0;
                lowerDiagonal[row+col] = 0;
            }
        }
    }
    
    
    
    
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            temp[i] = s;
        }
        vector<int> leftRow(n,0) , upperDiagonal(2*n-1,0) , lowerDiagonal(2*n-1,0);
        solve(0,temp,ans,leftRow,upperDiagonal,lowerDiagonal,n);
        return ans;
    }
};