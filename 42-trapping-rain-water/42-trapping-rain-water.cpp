class Solution {
public:
    int trap(vector<int>& height) {
        int left_max = 0;
        int right_max= 0;
        int water = 0;
        int lo = 0;
        int hi = height.size()-1;
        while(lo<hi){
            if(height[hi]>=height[lo]){
                if(height[lo]>left_max){
                    left_max = height[lo];
                } else{
                    water += left_max-height[lo];
                }
                lo++;
            } else{
                if(height[hi]>right_max){
                    right_max = height[hi];
                } else{
                    water+= right_max-height[hi];
                }
                hi--;
            }
        }
        return water;
    }
};