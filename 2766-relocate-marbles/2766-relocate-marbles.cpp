class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> st(nums.begin(),nums.end());
        
        for(int i=0;i<moveFrom.size();i++){
            if(st.find(moveFrom[i])!=st.end()){
                st.erase(moveFrom[i]);
                st.insert(moveTo[i]);
            }
        }
        vector<int> result(st.begin(),st.end());
        //sort(result.begin(),result.end());
        return result;
    }
};