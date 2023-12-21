class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // sort points (1,0),(1,4),(3,1),(5,3),(8,8),(9,0)
        sort(points.begin(),points.end());
        int currPoint = points[0][0];
        int maxPoint = INT_MIN;
        for(int i=1;i<points.size();i++){
            if(currPoint == points[i][0]) continue;
            else{
                maxPoint = max(maxPoint,(points[i][0]-currPoint));
                currPoint = points[i][0];
            }
        }
        if(maxPoint == INT_MIN){
            maxPoint = 0;
        }
        return maxPoint;
    }
};