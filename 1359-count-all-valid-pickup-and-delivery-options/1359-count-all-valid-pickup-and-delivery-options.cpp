class Solution {
public:
    const int MOD = 1e9 + 7;
    int countOrders(int n) {
       long long answer = 1; 
         for(int i = 2; i <= n; i++){
            answer = (answer * i * (2 * i - 1))%MOD;
        }

        return answer;
    }
};