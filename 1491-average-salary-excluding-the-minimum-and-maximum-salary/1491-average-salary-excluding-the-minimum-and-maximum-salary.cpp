class Solution {
public:
    double average(vector<int>& salary) {
        int maxi = 0;
        int mini = INT_MAX;
        double avg;
        for(int i=0;i<salary.size();i++){
            maxi = max(maxi ,salary[i]);
            mini = min(mini , salary[i]);
        }
        
        for(int i=0;i<salary.size();i++){
            if(salary[i]!= maxi && salary[i]!=mini)
                avg += salary[i];
        }
        return avg/(salary.size()-2);
    }
};