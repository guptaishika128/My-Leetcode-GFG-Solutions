class Solution {
public:
    bool isTimeEnough(vector<int>& time , long long int givenTime, int totalTrips){
        long long int curr_trips = 0;
        
        for(int t:time){
            curr_trips += (givenTime/t);
        }
        
        return curr_trips>=totalTrips;
    }
    
    
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
       
        long long int low = 1;
        long long int high = 1e14;
        
        while(low<high){
            long long int mid = (low+high)/2;
            
            if(isTimeEnough(time,mid,totalTrips)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};