class Solution {
public:
    
    int minTaps(int n, vector<int>& ranges) {
       int minReach = 0;
       int maxReach = 0 ;
        int ans =0;
        
        while(maxReach<n){
            
            for(int i=0;i<n+1;i++){
                if(i-ranges[i]<=minReach && i+ranges[i]>maxReach){
                    maxReach = i +ranges[i];
                }
            }
            
            if(minReach == maxReach){
                return -1;
            }
            
            minReach = maxReach;
            ans++;
        }
        return ans;
    }
};