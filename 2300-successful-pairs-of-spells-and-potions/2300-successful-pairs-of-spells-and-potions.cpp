class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
    vector<int> success1(spells.size(),0);
        
    
        for(int i=0;i<spells.size();i++){
           int s = 0;
           int e = potions.size()-1;
            int mid;
            while(s<=e){
                mid = s + (e-s)/2;
                
                if((long long int)spells[i]*(long long int)potions[mid]>= success){
                    e = mid-1;
                } else{
                    s = mid +1;
                }
            
            }
            success1[i] = potions.size()-1-e;
     }
    return success1;
    }
};