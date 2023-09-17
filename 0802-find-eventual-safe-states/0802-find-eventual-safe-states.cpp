class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> adjRev[v];
        vector<int> indegree(v);
        
        for(int i=0;i<v;i++){
            for(auto it:graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;        
            }
        }
        
         queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it:adjRev[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }

    }
        sort(topo.begin(),topo.end());
        return topo;
    }
};