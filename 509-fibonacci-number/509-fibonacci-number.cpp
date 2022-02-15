
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
       
        int fibn1 = fib(n-1) + fib(n-2);
        qb[n] = fibn1;
        return fibn1;
    }
};