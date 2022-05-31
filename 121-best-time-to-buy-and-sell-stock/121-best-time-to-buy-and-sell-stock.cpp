class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(prices.size() == 1){
            return 0;
        }
       
        int maxDiff = prices[1] - prices[0];
        int minElem = prices[0];
        
        for(int i=0;i<prices.size();i++){
            minElem = min(minElem,prices[i]);
            maxDiff = max(maxDiff,prices[i]-minElem);
        }
        
        return maxDiff;


    }
};