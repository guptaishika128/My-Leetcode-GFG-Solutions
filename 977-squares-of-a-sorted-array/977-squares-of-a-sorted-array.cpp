class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int l=0;
        int r=A.size()-1;
        vector<int> res(A.size());
        
        for (int k = A.size() - 1; k >= 0; k--) {
            if (abs(A[r]) > abs(A[l])) res[k] = A[r] * A[r--];
            else res[k] = A[l] * A[l++];
        }
        return res;
    }
};