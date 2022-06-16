class Solution {
public:
    int maxProfit(vector<int>& prices) {
         ios_base::sync_with_stdio(false);
         cin.tie(0);cout.tie(0);
	
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                profit +=  (prices[i]-prices[i-1]);
            }
        }
        return profit;
    }
};