class Solution {
public:
    
    bool isPossible(int mid, int m, int k,vector<int>& bloomDay){
        int cnt = 0;
        int noOfBouquets = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cnt++;
            } 
            else{
                noOfBouquets += (cnt/k);
                cnt = 0;
            }
        }
        noOfBouquets += (cnt/k);
        if(noOfBouquets>=m){
            return true;
        }
        return false;
            
    }
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if(n<(long long)m*(long long)k){
            return -1;
        }
        
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        
        int ans = INT_MAX;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(isPossible(mid,m,k,bloomDay)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};