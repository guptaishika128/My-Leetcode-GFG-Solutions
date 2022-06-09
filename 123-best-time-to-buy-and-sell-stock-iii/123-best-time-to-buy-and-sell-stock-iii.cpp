class Solution {
public:
    int maxProfit(vector<int>& prices) {
    /*    int n = prices.size();
        int lsf = prices[0];
        int mpist = 0;
        int dpl[n];
        dpl[0] = 0;
        for(int i=1;i<n;i++){
            if(prices[i]<lsf){
                lsf=prices[i];
            }
            mpist = prices[i] - lsf;
            if(mpist>dpl[i-1]){
                dpl[i]=mpist;
            }else{
                dpl[i] = dpl[i-1];
            }
        }
        
        int maxsf = prices[n-1];
        int mpibt = 0;
        int dpr[n];
        dpr[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            if(prices[i]>maxsf){
                maxsf=prices[i];
            }
            mpibt = maxsf-prices[i];
            if(mpibt>dpr[i+1]){
                dpr[i] =mpibt; 
            }else{
                dpr[i] = dpr[i+1];
            }
        }
        
        int overallprofit = 0;
        for(int i=0;i<n;i++){
            if(overallprofit<dpr[i]+dpl[i]){
                overallprofit = dpr[i]+dpl[i];
            }
        }
        return overallprofit;
        */
        int buy1 = INT_MAX;
        int profit1 = INT_MIN;
        int buy2 = INT_MAX;
        int profit2 = INT_MIN;
        
        for(int i=0;i<prices.size();i++){
            buy1 = min(buy1,prices[i]);
            profit1 = max(profit1 , prices[i]-buy1);
            buy2 = min(buy2 , prices[i]-profit1);
            profit2 = max(profit2,prices[i]-buy2);
        }
        return profit2;
    }
};