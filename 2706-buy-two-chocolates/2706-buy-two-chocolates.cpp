class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        
        int leftover = money-prices[0]-prices[1];
        
        if(leftover>=0){
            return leftover;
        }
        return money;
    }
};