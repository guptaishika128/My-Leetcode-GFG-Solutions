class Solution {
public:
    
    int count(int m , int n , int mid){
        int ans = 0;
        for(int i=1;i<=m;i++){
            ans += min(mid/i,n);
        }
        return ans;
    }    
    
    int findKthNumber(int m, int n, int k) {
        int ele = 0;
        
        int high = m*n;
        int low = 1;
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            
            int cnt = count(m,n,mid);
            if(cnt < k){
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