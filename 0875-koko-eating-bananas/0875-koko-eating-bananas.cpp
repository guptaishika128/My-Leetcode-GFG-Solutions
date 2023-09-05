class Solution {
public:
    bool ifSatisfies(int mid, int h, vector<int>&piles){
        long long sum  = 0;
        
        for(int i=0;i<piles.size();i++){
            sum += ceil((double)piles[i]/(double)mid);
        }
        if(sum<=h){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        
        int ans = INT_MAX;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(ifSatisfies(mid,h,piles)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};