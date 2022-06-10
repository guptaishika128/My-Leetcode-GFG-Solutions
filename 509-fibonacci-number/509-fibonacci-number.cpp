
class Solution {
public:
    int qb[31];
    int fib(int n) {
        
        if(n<=1){
            return n;
        }
        
        if(qb[n] != 0){
            return qb[n];
        }
      
        return qb[n] = fib(n-1) + fib(n-2);
    }
};