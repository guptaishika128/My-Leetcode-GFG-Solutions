using ll = long long;
class Solution {
public:
    
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
    
       vector<ll> maxRow(row,0);
        vector<ll> maxCol(col,0);
        
        
        map<int,vector<pair<int,int>>,greater<int>> mp;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mp[mat[i][j]].push_back({i,j});
            }
        }
        ll result = 0;
        
        for(auto& it:mp){
            vector<pair<int,int>>& temp = it.second;
            vector<ll> val(temp.size());
            
            for(int i=0;i<temp.size();i++){
                int x = temp[i].first;
                int y = temp[i].second;
                val[i] = max(maxRow[x],maxCol[y])+1;
                result = max(result,val[i]);
            }
            
            for(int i=0;i<temp.size();i++){
                int x = temp[i].first;
                int y = temp[i].second;
                maxRow[x] = max(maxRow[x],val[i]);
                maxCol[y] = max(maxCol[y],val[i]);
            }
        }
        return result;
        
    }
};