class Solution {
public:
 /* TC- O(N)
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

*/
    vector<int> countBits(int n) {
     /*   vector<int> res;
        for(int i=0;i<=n;i++){
            int a = countOne(i);
            res.push_back(a);
        }
        return res;
    */
        
        vector<int> dp(n+1,0);
     int offset = 1;
        for(int i=1;i<n+1;i++){
            if(offset*2 == i){
                offset = i;
            }
            dp[i] = 1+dp[i-offset];
        }
        return dp;
    }
};