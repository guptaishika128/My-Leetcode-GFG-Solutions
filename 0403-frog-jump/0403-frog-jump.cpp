class Solution {
public:
    int dp[2001][2001];
    bool solve(vector<int>& stones , int idx, int k){
        if(idx == stones.size()-1){
            return true;
        }
        if(idx>=stones.size()){
            return false;
        }
    
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
      
        bool ans = false;
        
        for(int t=-1;t<2;t++){
            int next_jump = k+t;
            
            if(next_jump>0){
                
                int in = lower_bound(stones.begin(),stones.end(),stones[idx] + next_jump) - stones.begin();
                
            if(in == stones.size() || stones[in] != stones[idx]+next_jump){
                continue;
            }
             ans = ans || solve(stones,in,next_jump);   
            }
        }
        
        return dp[idx][k] = ans;
       
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]>1){
            return false;
        }
        if(stones.size()==2){
            return (stones[1]-stones[0] == 1);
        }
//         unordered_map<int,int> mp;
        
//          for (int i = 0; i < stones.size(); i++) {
//             mp[stones[i]] = i;
//         }
        
         memset(dp,-1,sizeof(dp));
        return solve(stones,0,0);
    }
};