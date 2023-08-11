class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        unordered_map<int, int> mp;
        
        for(int i=0;i<numbers.size();i++){
            if(mp.find(target-numbers[i])!=mp.end()){
                result.push_back(mp[target-numbers[i]]+1);
                result.push_back(i+1);
            }
            else{
                mp[numbers[i]] = i;
            }
        }
        return result;
    }
};