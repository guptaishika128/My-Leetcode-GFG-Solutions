class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        
        int totalY = 0;
        for(int i=0;i<n;i++){
            if(customers[i] == 'Y'){
               totalY++;
               }
        }
               
        int cntY = 0;
        int cntN = 0;
               int ans = totalY;
        int ind = 0;
        for(int i=0;i<n;i++){
            if(customers[i] == 'Y'){
                cntY++;
            }
            else{
                cntN++;
            }
            int val = (totalY-cntY) + cntN;
            if(val<ans){
                ans = val;
                ind = i+1;
            }
        }
               return ind;
    }
};