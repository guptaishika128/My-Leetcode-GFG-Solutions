class DisjointSet{
 
public:
    vector<int> parent,rank,size;
    
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        } else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    int getLargetComponentSize() {
            int maxSize = 0;
            for (int i = 0; i < parent.size(); i++) {
                if (parent[i] == i && size[i] > maxSize) {
                    maxSize = size[i];
                }
            }
            
            return maxSize;
        }

};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
//         sort(nums.begin(),nums.end()); // Distorting the array 
        int n = nums.size();
        if(n<=1){
            return n;
        }
        
//         int currentStreak = 1;
//         int maxi = 0;
        
//         for(int i=1;i<nums.size();i++){
//             if(nums[i] != nums[i-1]){
//                 if(nums[i] == (nums[i-1] + 1)){
//                     currentStreak++; 
//                 } 
//                 else{
//                      maxi = max(maxi , currentStreak);
//                     currentStreak = 1;
//                 }
//             } 
//         }
//         return max(maxi,currentStreak);
        
//         int maxi = 1;
//         unordered_set<int> s;
        
//         for(int i=0;i<nums.size();i++){
//             s.insert(nums[i]);
//         }
        
//         for(auto it:s){
//             if(s.find(it-1) == s.end()){
//                 int curr =1;
//                 int x = it;
//                 while(s.find(x+1) != s.end()){
//                     curr++;
//                     x =x+1;
//                 }
//                 maxi = max(maxi,curr);
//             }
//         }
//         return maxi;
        
        DisjointSet ds(n);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!= mp.end()){
                continue;
            }
            if(mp.find(nums[i]-1)!= mp.end()){
                ds.unionBySize(i,mp[nums[i]-1]);
            }
            if(mp.find(nums[i]+1) != mp.end()){
                ds.unionBySize(i,mp[nums[i]+1]);
            }
            mp.insert({nums[i],i});
        }
      return ds.getLargetComponentSize();
    }
};