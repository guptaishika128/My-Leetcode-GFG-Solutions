class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         int n=matrix.size();
        int m=matrix[0].size();
        int minr = 0;
        int minc = 0;
        int maxr = n-1;
        int maxc = m-1;
        int cne = 0;
        int totalelem = m*n;
        vector<int> result;
        if(n==0){
            return result;
        }
        while(cne<totalelem){
            
        for(int j=minc ; j<=maxc && cne<totalelem;j++){
            result.push_back(matrix[minr][j]);
           cne++;
        }
        minr++;
        
        for(int i=minr;i<=maxr && cne<totalelem;i++){
            result.push_back(matrix[i][maxc]);
            cne++;
        }
        maxc--;
        
        for(int j=maxc;j>=minc && cne<totalelem;j--){
            result.push_back(matrix[maxr][j]);
            cne++;
        }
        maxr--;
        
        for(int i=maxr;i>=minr && cne<totalelem;i--){
            result.push_back(matrix[i][minc]);
            cne++;
        }
        minc++;
    }
    return result;
    }
};