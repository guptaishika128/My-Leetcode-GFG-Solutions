class Solution {
public:
     vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0) return vector<vector<int>>() ;
        //no need to sort nums to save time
        vector<vector<int>> res ;
        dfs(nums,0,res) ;
        return res;
    }
    void dfs(vector<int>& nums, int index , vector<vector<int>>& res)
    {
        if(index == nums.size() ) 
        {
            res.push_back(nums);
            return ;
        }
        unordered_set<int> record ;
        for(int i = index ; i < nums.size() ; i++)
        {
            if(record.find(nums[i]) != record.end() )
                continue ;
            record.insert(nums[i]);
            swap(nums[i] , nums[index]);
            dfs(nums,index+1,res);
            swap(nums[i] , nums[index]);
        }
    }
};