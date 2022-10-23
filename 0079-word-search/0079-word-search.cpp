class Solution {
public:
    int dx[4] = {0,1,-1,0} ; 
    int dy[4] = {1,0,0,-1} ; 
    bool visited[7][7] ; 
    bool work (vector<vector<char>>& grid , int x , int y , string& word,int idx = 1){ 
        if (idx == word.size())
            return true ; 
        int n = grid.size() ; 
        int m = grid[0].size() ;
        visited[x][y] = true ; 
        for (int i = 0 ; i<4 ; i++){
            int nx = x+dx[i] ; 
            int ny = y+dy[i] ; 
            if (nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny] == word[idx]){
                if (visited[nx][ny]) continue ; 
                if (work(grid,nx,ny,word,idx+1))
                    return true ; 
            }
        }
        visited[x][y] = false ; 
        return false ; 
    }
    bool exist(vector<vector<char>>& board, string& word) {
        int n = board.size() ; 
        int m = board[0].size() ; 
        if (n*m<word.size())
            return false; 
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                if (board[i][j] == word[0]){
                   // memset(visited,false,sizeof(visited)) ; 
                    if (work(board,i,j,word))
                        return true ; 
                }
            }
        }
        return false ; 
    }
};