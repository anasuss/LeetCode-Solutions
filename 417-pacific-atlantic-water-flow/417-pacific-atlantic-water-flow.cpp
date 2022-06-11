class Solution {
public:
 int dx[4] = {0,1,0,-1} ;

int dy[4] = {1,0,-1,0} ;

bool isvalide(int x , int y,int n , int m){
    return x>=0 && y>=0 && x<n && y<m ;
}

bool bfs(int x , int y,vector<vector<int>>& heights){
    queue<pair<int,int>> q ;
    int n = (int)heights.size() ;
    int m = (int)heights[0].size() ;
    bool visited[n][m] ;
    memset(visited,false,sizeof(visited)) ;
    q.push({x,y}) ;
    visited[x][y] = true ;
    bool PO = false ;
    bool PA = false ;
    if (x == 0 || y == 0)
        PO = true ;
    if (x == n-1 || y == m-1)
        PA = true ;
    if (PO && PA )
        return true ;
    while(!q.empty()){
        pair<int,int> p = q.front() ;
        q.pop() ;
        x = p.first ;
        y = p.second ;
        for (int i = 0 ; i<4 ; i++){
            int nx = x+dx[i] ;
            int ny = y+dy[i] ;
            if (isvalide(nx,ny,n,m) && heights[nx][ny]<=heights[x][y] && !visited[nx][ny]){
                q.push({nx,ny}) ;
                visited[nx][ny] = true ;
                if (nx == 0 || ny == 0)
                        PO = true ;
                if (nx == n-1 || ny == m-1)
                        PA = true ;
                if (PO && PA)
                    return true ;
            }
        }
    }
    return false ;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> ans ;
    vector<int> v ;
    int n = (int)heights.size() ;
    int m = (int)heights[0].size() ;
    for (int i = 0 ; i<n ; i++){
        for (int j = 0 ; j<m ; j++){
            if (bfs(i,j,heights)){
                v.push_back(i); v.push_back(j) ;
                ans.push_back(v) ;
                v.clear() ;
            }
        }
    }
    return ans ;
}

};