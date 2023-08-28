class Solution {
public:
       
    vector<vector<int>> findPrimePairs(int n) {
        // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    
        
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
        
        vector<vector<int>> ans;
        if(n<=2){
            return ans;
        }
        
        for(int i=1;i<=n/2;i++){
            if(prime[i] && prime[n-i]){
                ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};