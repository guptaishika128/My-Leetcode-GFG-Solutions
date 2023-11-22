class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Floyd Warshall Algo - To find the shortest distance from each and every city
        vector<vector<int>> distance(n,vector<int>(n,1e8));
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            distance[u][v] = wt;
            distance[v][u] = wt;
        }
        
        for(int i=0;i<n;i++){
            distance[i][i] = 0;
        }
        
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(distance[i][via]!=1e8 && distance[via][j]!=1e8){
                        distance[i][j] = min(distance[i][j] ,(distance[i][via]+distance[via][j]));
                    }
                }
            }
        }
        
        int maxCity = n;
        int cityno = -1;
        
        for(int city=0;city<n;city++){
            int cnt = 0;
            for(int adjCity=0;adjCity<n;adjCity++){
                if(distance[city][adjCity]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=maxCity){
                maxCity = cnt;
                cityno = city;
            }
        }
        return cityno;
    }
};