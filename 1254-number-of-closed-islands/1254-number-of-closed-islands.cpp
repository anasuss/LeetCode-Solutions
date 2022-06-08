class Solution {
public:
   const int N = 105 ;


bool visited[105][105] ;

int dx[4] = {1,-1,0,0} ;

int dy[4] = {0,0,1,-1} ;

bool isvalide(int x , int y , int n , int m){
    return x>=0 && y>=0 && x<n && y<m ;
}

void dfs(vector<vector<int>>& grid , int x , int y , int n , int m , bool &check){

    if (visited[x][y])
        return ;

    visited[x][y] = true ;

    if (x == 0 || y == 0 || x == n-1 || y == m-1){
        check = true ;
    }
    for (int i = 0 ; i<4 ; i++){
        int nr = x+dx[i] ;
        int nc = y+dy[i] ;
        if (isvalide(nr,nc,n,m)&& grid[nr][nc] == 0){
            dfs(grid,x+dx[i],y+dy[i],n,m,check) ;
        }
    }
}

int closedIsland(vector<vector<int>>& grid) {
    int n = grid.size() ;
    int m = grid[0].size() ;
    for (int i = 0 ;i<n ; i++){
        for (int j = 0 ; j<m ; j++)
            visited[i][j] = false ; 
    }
    int ans = 0 ;
    for (int i = 0 ; i<n ; i++){
        for (int j = 0 ; j<m ; j++){
            if (grid[i][j] == 0 && !visited[i][j]){
                bool check = 0 ;
                dfs(grid,i,j,n,m,check) ;
                if (i == 0 || j == 0 || i == n-1 || j == m-1 || check){
                    continue ;
                }
                ans+=1 ;
            }
        }
    }
    return ans ;
}

};