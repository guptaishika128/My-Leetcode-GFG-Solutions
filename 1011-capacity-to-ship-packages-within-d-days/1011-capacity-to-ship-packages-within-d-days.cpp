class Solution {
public:
    
    int solve(vector<int> weights, int mid){
        int noOfdays = 1;
        long long curr_sum = 0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]+curr_sum <= mid){
                curr_sum += weights[i];
            }
            else{
                curr_sum = weights[i];
                noOfdays++;
            }
        }
        return noOfdays;
    }
    
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            
            int daysCount = solve(weights,mid);
            if(daysCount>days){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};