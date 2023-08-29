class Solution {
public:
    int bestClosingTime(string customers) {
        int start = 0;
        int ans = 0;
        int n = customers.length();
        int curr = 0;
        
        for(int i=0;i<n;i++){
            if(customers[i] == 'Y'){
                curr++;
            } else if(customers[i] == 'N'){
                curr--;
            }
            if(ans<curr){
                ans = curr;
                start = i+1;
            }
        }
        return start;
    }
};