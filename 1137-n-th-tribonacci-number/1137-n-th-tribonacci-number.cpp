class Solution {
public:
    int tb[38];
    int tribonacci(int n) {
       
        if(n<=1){
            return n;
        }
        if(n==2){
            return 1;
        }
        if(tb[n]!=0){
            return tb[n];
        }
        
        
        int trib = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        tb[n] = trib;
        return trib;
    }
};