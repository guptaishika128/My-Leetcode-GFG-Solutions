class Solution {
public:
    int minLength(vector<string>& strs, int n){
        int minNo = strs[0].size();
        
        for(int i=1;i<n;i++){
            if(strs[i].size()<minNo){
                minNo = strs[i].size();
            }
        }
        
        return minNo;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        
        int minlen = minLength(strs,n);
        
         string result; 
    char current; 
 
    for (int i=0; i<minlen; i++)
    {
        // Current character (must be same
        // in all strings to be a part of
        // result)
        current = strs[0][i];
 
        for (int j=1 ; j<n; j++)
            if (strs[j][i] != current)
                return result;
 
        // Append to result
        result.push_back(current);
    }
 
    return (result);
        
        
        
        
    }
};