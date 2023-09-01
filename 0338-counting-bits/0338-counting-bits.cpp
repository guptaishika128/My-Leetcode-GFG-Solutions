class Solution {
public:

 int countOne(int n){
        int count = 0;
        while(n>0){
            int rem = n%2;
            n=n/2;
            if(rem==1){
            count++;
            }
        }
        return count;
    }


    vector<int> countBits(int n) {
       // vector<int> res;
       //  for(int i=0;i<=n;i++){
       //      int a = countOne(i);
       //      res.push_back(a);
       //  }
       //  return res;
    
        
        vector<int> dp(n+1,0);
        dp[0] = 0;
        for(int i=1;i<n+1;i++){
            dp[i] = dp[i>>1] + (i&1);
        }
        return dp;
    }
};