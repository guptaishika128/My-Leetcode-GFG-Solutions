class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int mon_amount = 1;
        while(n>0){
            for(int day=0;day<min(7,n);day++){
                ans += day+mon_amount;
            }
            n-=7;
            mon_amount++;
        }
        return ans;
    }
};