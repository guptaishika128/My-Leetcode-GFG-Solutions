class Solution {
public:
   
    
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<long long> pq(gifts.begin(),gifts.end());
       
        
        long long sum = 0;
        
        while(k--){
            int topEle = pq.top();
            pq.pop();
            pq.push(floor(sqrt(topEle)));
        }
        
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
        
    }
};