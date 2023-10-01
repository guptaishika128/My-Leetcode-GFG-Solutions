class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> v1 = edges[0];
        vector<int> v2 = edges[1];
        
        
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                if(v1[i] == v2[j]){
                    return v1[i];
                }
            }
        }
        return 0;
    }
};