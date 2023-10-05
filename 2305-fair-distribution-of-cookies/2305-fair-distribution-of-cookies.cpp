class Solution {
public:
    int res = INT_MAX;
    void dfs(vector<int>& cookies, vector<int>& children, int idx,int maxi)
    {
        if(idx>=cookies.size()){
            res = min(res,maxi);
            return;
        }
        int c = cookies[idx];
        
        for(int i=0;i<children.size();i++){
            children[i] += c;
            dfs(cookies,children,idx+1,max(maxi,children[i]));
            children[i] -= c;
        }
    }
    
    
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k);
        dfs(cookies,children,0,0);
        return res;
        
    }
};