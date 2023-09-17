//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int> adj[], vector<int>& visited,vector<int>& path){
        visited[node] = 1;
        path[node] = 1;
        
        //Traverse adjacent nodes
        for(auto it:adj[node]){
            
            if(!visited[it]){
                if(dfs(it,adj,visited,path)==true){
                    return true;
                }
            }
            
            else if(path[it]){
                return true;
            }
        }
        
        path[node] = 0;
        return false;
    }
    

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
         vector<int> visited(V,0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,path);
            }
        }
        
        vector<int> ans;
        
        for(int i=0;i<V;i++){
            if(!path[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends