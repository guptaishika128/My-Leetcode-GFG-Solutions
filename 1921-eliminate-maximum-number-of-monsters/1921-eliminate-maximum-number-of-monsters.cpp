class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time(n);
        
        for(int i=0;i<n;i++){
            time[i] = (double)dist[i]/speed[i];
        }
        sort(time.begin(),time.end());
        double curr_time = 0.0;
        int count = 0;
        
        for(int i=0;i<n;i++){
           if(time[i]>curr_time){
               count++;
           }
            else{
                return count;
            }
            curr_time = curr_time + 1.0;
        }
        return count;
        
    }
};