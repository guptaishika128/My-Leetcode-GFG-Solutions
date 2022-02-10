class Solution {
public:
    int fib(int n) {
        vector<int> qb(n+1,0);
        
         if(n<=1){
            return n;
        }
        
       qb[0] = 0;
       qb[1] =1;
        
        for(int i=2;i<=n;i++){
            qb[i] = qb[i-1] + qb[i-2];
        }
        return qb[n];
    }
};