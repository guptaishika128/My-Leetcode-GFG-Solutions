class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int,set<int>> mp;
        
        for(int i=0;i<logs.size();i++){
            int id = logs[i][0];
            int time = logs[i][1];
            mp[id].insert(time);
        }
        vector<int> res(k,0);
        
        for(auto i:mp){
            res[i.second.size()-1]++;
        }
        return res;
    }
};