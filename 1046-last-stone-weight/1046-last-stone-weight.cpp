class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        
        while(pq.size()>1){
            int y = pq.top();
            pq.pop();
            int z = pq.top();
            pq.pop();
            if(y!=z){
                pq.push(y-z);
            }
        }
         return pq.empty()? 0 : pq.top();
    } 
};