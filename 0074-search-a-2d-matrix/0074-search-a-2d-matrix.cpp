class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        
        bool flag = false;
        for(i=0;i<m;i++){
            if(matrix[i][n-1]>target){
                flag = true;
                break;
            }
            else if(matrix[i][n-1]==target){
                return true;
            }
        }
        if(flag == false){
            return false;
        }
        
        for(int j=0;j<n;j++){
            if(matrix[i][j] == target){
                return true;
            }
        }
        return false;
    }
};