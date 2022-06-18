class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int obsp = -prices[0];
        int ossp = 0;
        
        for(int i=0;i<prices.size();i++){
            int nbsp = 0;
            int nssp = 0;
            
            if(ossp-prices[i]>obsp){
                nbsp = ossp - prices[i];
            } else{
                nbsp = obsp;
            }
            
            if((prices[i] + obsp - fee) > ossp){
                nssp = prices[i]+obsp-fee;
            } else{
                nssp = ossp;
            }
            
            obsp = nbsp;
            ossp = nssp;
        }
        return ossp;
    }
};