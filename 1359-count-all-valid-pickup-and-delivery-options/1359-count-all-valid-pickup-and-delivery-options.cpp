class Solution {
public:
    const int MOD = 1e9 + 7;
    int countOrders(int n) {
       long long ans = 1; 
        for(int i=2;i<=n;i++){
            int space = 2*(i-1) + 1;
            ans *= space*(space+1)/2;
            ans = ans%MOD;
        }
        
        return ans;
    }
};