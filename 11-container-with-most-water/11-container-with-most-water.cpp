class Solution {
public:
    int maxArea(vector<int>& height) {
        int volume=0;
        int start=0,end=height.size()-1;
        while(start<end){
            int h=min(height[end],height[start]);
            volume=max(volume,h*(end-start));
            while(height[start]<=h && start<end)
                start++;
            while(height[end]<=h && start<end)
                end--;
        }
        return volume;
    
    }
};