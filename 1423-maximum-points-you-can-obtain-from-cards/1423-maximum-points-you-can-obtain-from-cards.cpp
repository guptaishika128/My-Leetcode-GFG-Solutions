class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // Sliding Window approach
        
        int sum =0;
        int maxsum;
        
        for(int  i=0;i<k;i++){
            sum += cardPoints[i];
        }
        maxsum = sum;
        
        for(int i=0;i<k;i++){
            sum += cardPoints[cardPoints.size()-i-1] - cardPoints[k-i-1];
            if(sum > maxsum){
                maxsum = sum;
            }
        }
        return maxsum;
    }
};