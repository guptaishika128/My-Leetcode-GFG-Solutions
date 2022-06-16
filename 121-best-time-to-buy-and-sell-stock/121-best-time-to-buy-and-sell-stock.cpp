class Solution {
public:
    int maxProfit(vector<int>& prices) {
         ios_base::sync_with_stdio(false);
         cin.tie(0);cout.tie(0);
	
       int n= prices.size();
       int maxprofit = INT_MIN;
        int minprice = prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]<minprice){
                minprice = prices[i];
            } else if(prices[i]-minprice>maxprofit){
                maxprofit = prices[i]-minprice;
            }
        }
        return maxprofit;
    }
};