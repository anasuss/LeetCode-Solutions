class Solution {
public:
    int cnt = 0 ;

bool visited[505][505] ;

int dx[4] = {1,-1,0,0} ;

int dy[4] = {0,0,1,-1} ;

bool isvalide(int x , int y , int n , int m){
    return x>=0 && y>=0 && x<n && y<m ;
}

void dfs(vector<vector<char>>& grid , int x , int y , int n , int m , bool &check , int par_r , int par_c ,char c){

     if (visited[x][y] ){
         check = true ; 
        return ; 
    }
     
    visited[x][y] = true ;
    
    
    for (int i = 0 ; i<4 ; i++){
        int nr = x+dx[i] ;
        int nc = y+dy[i] ;
        if (nr == par_r && nc == par_c)
            continue ; 
        if (isvalide(nr,nc,n,m) && grid[nr][nc] == c && !check){
            dfs(grid,x+dx[i],y+dy[i],n,m,check,x,y,c) ;
        }
    }
}

bool containsCycle(vector<vector<char>>& grid) {
    int n = grid.size() ;
    int m = grid[0].size() ;
    int ans = 0 ;
    bool det = 0 ;
    for (int i = 0 ; i<n ; i++)
        for (int j = 0 ; j<m ; j++)
            visited[i][j] = false ;
    for (int i = 0 ; i<n && !det; i++){
        for (int j = 0 ; j<m ; j++){
            if (!visited[i][j]){
                char c = grid[i][j] ;
                cnt = 0 ;
                dfs(grid,i,j,n,m,det,-1,-1,c) ;
                if (det)
                    break ;
                visited[i][j] = true ;
            }
        }
    }
    return det ;
}

};