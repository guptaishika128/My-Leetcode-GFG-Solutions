class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
         vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        
        string end = "123450";
        string initial = "";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                initial += to_string(board[i][j]); 
            }
        }
        
        unordered_set<string> st; // to keep track
        queue<pair<string,int>> q; 
        int steps = 0;
        
        q.push({end,5});
        st.insert(end);
        
        while(!q.empty()){
           int size=q.size();


            while(size--){
                auto it =q.front();
                q.pop();
                string curr=it.first;
                
                if(curr==initial)return steps;
                int pos=it.second;

                for(auto i: moves[pos]){
                    swap(curr[i] , curr[pos]); //swapping 
                    if(st.find(curr)==st.end()){
                        st.insert(curr);
                        q.push({curr,i});
                    }
                    swap(curr[i],curr[pos]);  //getting back orignal
                }

            }


            steps++;
            
            
        }
        return -1;
    }
};