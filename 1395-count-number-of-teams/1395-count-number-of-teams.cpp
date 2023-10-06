class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int cnt = 0;
        
        for(int i=1;i<n-1;i++){
            int leftGreater = 0, leftLess = 0, rightLess = 0, rightGreater = 0;
            
            for(int k=0;k<i;k++){
                if(rating[k]>rating[i]){
                    leftGreater++;
                }
                else{
                    leftLess++;
                }
            }
            
            for(int k=n-1;k>i;k--){
                if(rating[k]>rating[i]){
                    rightGreater++;
                }
                else{
                    rightLess++;
                }
            }
            cnt += (leftGreater*rightLess) + (leftLess*rightGreater);
        }
        return cnt;
    }
};