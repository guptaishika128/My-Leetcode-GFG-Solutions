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
    int left[prices.size()];
    int right[prices.size()];
    left[0]=0;
    
    int mini=prices[0];
    for(int i=1;i<prices.size();i++){
        mini=min(mini,prices[i]);
        left[i]=max(prices[i]-mini,left[i-1]);
    }
    right[prices.size()-1]=0;
    int maxi=prices.back();
    int res=0;
    for(int i=prices.size()-2;i>=0;i--){
        maxi=max(prices[i],maxi);
        right[i]=max(right[i+1],maxi-prices[i]);
        res=max(res,right[i]+left[i]);
    }
    return res;
    }
};