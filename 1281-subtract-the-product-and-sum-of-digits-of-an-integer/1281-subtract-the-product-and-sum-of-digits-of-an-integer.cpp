class Solution {
public:
    int subtractProductAndSum(int n) {
       int product = 1;
        int sum =0;
        while(n){
            int res = n%10;
            n= n/10;
            product *= res;
            sum += res;
        }
        return (product-sum);
    }
};