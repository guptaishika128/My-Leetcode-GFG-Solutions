class Solution {
public:
    int countLiveNeighbours(vector<vector<int>>& board, int i, int j, int m, int n){
        int ln=0; // To store count of live neighbors
        
        if(i>0){
            if(board[i-1][j] == 1 || board[i-1][j] == 3){
                ln++;
            }
        }
        
        if(i<m-1){
            if(board[i+1][j] ==1 || board[i+1][j] == 3){
                ln++;
            }
        }
        
        if(j>0){
            if(board[i][j-1] == 1 || board[i][j-1] == 3){
                ln++;
            }
        }
        
        if(j<n-1){
            if(board[i][j+1] == 1 || board[i][j+1] == 3){
                ln++;
            }
        }
        
        if(i>0 && j>0){
            if(board[i-1][j-1] == 1 || board[i-1][j-1] ==3){
                ln++;
            }
        }
        
        if(i>0 && j<n-1){
            if(board[i-1][j+1] == 1 || board[i-1][j+1] == 3){
                ln++;
            }
        }
        
        if(i<m-1 && j>0){
            if(board[i+1][j-1] == 1 || board[i+1][j-1] == 3){
                ln++;
            }
        }
        
        if(i<m-1 && j<n-1){
            if(board[i+1][j+1] == 1 || board[i+1][j+1] ==3){
                ln++;
            }
        }
        return ln;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int liven = countLiveNeighbours(board,i,j,m,n);
                if(board[i][j]==0){
                    
                    if(liven==3){
                        board[i][j] = 2; // newly alive
                    }
                }
                if(board[i][j]==1){
                    if(liven<2 || liven>3){
                        board[i][j] = 3; // newly daed
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==2){
                    board[i][j] = 1;
                }
                if(board[i][j]==3){
                    board[i][j] = 0;
                }
            }
        }
    }
};