class Solution {
public:
    int climbStairs(int n) {
       long long int prev = 1;
       long long int prev2 = 1;
        for(int i=1;i<=n;i++){
            int curi = prev + prev2;
            prev2 = prev;
            prev = curi;
            
        }
        return prev2;
    }
};