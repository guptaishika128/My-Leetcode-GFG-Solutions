#include<algorithm>
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const int MOD = 1e9 + 7;
        
         long int maxWidth = 0;
        long int maxHeight =0;
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        for(int i=0 ,prev = 0;i<horizontalCuts.size();i++){
            maxHeight = max(maxHeight,(long int)horizontalCuts[i]-prev);
            prev = horizontalCuts[i];
        }
        
        for(int i=0 ,prev = 0;i<verticalCuts.size();i++){
            maxWidth = max(maxWidth,(long int)verticalCuts[i]-prev);
            prev = verticalCuts[i];
        }
        
        return (maxHeight*maxWidth)%MOD;
    }
};