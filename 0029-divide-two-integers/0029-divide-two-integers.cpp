class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor){
            return 1;
        }
        bool isPositive = (dividend>0 == divisor>0);
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        
        unsigned int ans = 0;
        while(a>=b){ // while dividend is greater or equal to divisor
            short q = 0;
            while(a > (b<<(q+1))){
                q++;
            }
            ans += (1<<q); // add power of 2 into the ans
            a = a - (b<<q); // reduce the dividend 
        }
        
        if(ans == (1<<31) && isPositive){
            return INT_MAX;
        }
        return isPositive?ans:-ans;
    }
};