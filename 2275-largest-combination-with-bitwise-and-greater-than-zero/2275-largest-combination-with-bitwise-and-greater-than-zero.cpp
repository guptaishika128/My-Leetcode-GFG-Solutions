class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bits(32);
        
        for(int i=0;i<candidates.size();i++){
            int temp = 31;
            while(candidates[i]>0){
                bits[temp] += candidates[i]%2;
                candidates[i] = candidates[i]/2;
                temp--;
            }
        }
        
        int maxi = 0;
        
        for(int i=0;i<32;i++){
            maxi = max(maxi,bits[i]);
        }
        return maxi;
    }
};