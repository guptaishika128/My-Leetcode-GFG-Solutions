class Solution {
public:
    int countPrimes(int n) {
        bool prime[n+1];
        memset(prime,true,sizeof(prime));
        if(n<=2){
            return 0;
        }
        prime[0] = false;
        prime[1] = false;
        
        for(int p=2 ;p*p<=n;p++){
            if(prime[p] == true){
                for(int i=p*p;i<=n;i+=p){
                    prime[i] = false;
                }
            }
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(prime[i]){
                cnt++;
            }
        }
        return cnt;
    }
};