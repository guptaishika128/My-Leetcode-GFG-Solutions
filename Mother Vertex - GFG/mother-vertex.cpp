//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    
    void dfs(int node, vector<int> adj[], vector<int>& visited){
        visited[node] = 1;
        
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
    
    
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> visited(V,0); // visited array
	    
	    int v = 0; // to store last finished vertex
	    
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(i,adj,visited);
	            v = i;
	        }
	    }
	    
	    fill(visited.begin(),visited.end(),0);
	    
	    dfs(v,adj,visited);
	    
	    for(int i=0;i<V;i++){
	        if(visited[i] == 0){
	            return -1;
	        }
	    }
	    return v;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends