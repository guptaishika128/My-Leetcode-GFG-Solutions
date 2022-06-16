class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
         ios_base::sync_with_stdio(false);
         cin.tie(0);cout.tie(0);
	
        if(values.size()==2){
            return (values[0]+values[1]-1);
        }
        
        int currmax_score = values[0] + 0;
        int res= -1;
        
        for(int i=1;i<values.size();i++){
            res= max(res, currmax_score+ values[i]-i);
            currmax_score = max(currmax_score, values[i]+i);
        }
        return res;
    }
};