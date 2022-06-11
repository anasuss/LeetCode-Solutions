class Solution {
public:
int dx[4] = {0,1,0,-1} ;

int dy[4] = {1,0,-1,0} ;

bool isvalide(int x , int y,int n , int m){
    return x>=0 && y>=0 && x<n && y<m ;
}

void bfs(vector<vector<int>>& heights , vector<vector<bool>> &visited , vector<pair<int,int>> &occ){
    queue<pair<int,int>> q ;
    int n = heights.size() ;
    int m = heights[0].size() ;
    for (int i = 0 ; i<occ.size() ; i++){
        q.push(occ[i]);
        visited[occ[i].first][occ[i].second] = true ;
    }
    while(!q.empty()){
        pair<int,int> p = q.front() ;
        q.pop() ;
        int x = p.first ;
        int y = p.second ;
        for (int i = 0 ; i<4 ; i++){
            int nx = x+dx[i] ;
            int ny = y+dy[i] ;
            if (isvalide(nx,ny,n,m) && heights[nx][ny]>=heights[x][y] && !visited[nx][ny]){
                q.push({nx,ny}) ;
                visited[nx][ny] = true ;
            }
        }
    }
    return  ;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> ans ;
    int n = (int)heights.size() ;
    int m = (int)heights[0].size() ;
    vector<vector<bool>> visited1(n, vector<bool>(m,false));
    vector<vector<bool>> visited2(n, vector<bool>(m,false));
    vector<pair<int,int>> po ;
    vector<pair<int,int>> ao ;
    for (int i = 0 ; i<n ; i++){
        po.push_back({i,0}) ;
        ao.push_back({i,m-1}) ;
    }
    for (int i = 0 ; i<m ; i++){
        po.push_back({0,i}) ;
        ao.push_back({n-1,i}) ;
    }
    bfs(heights,visited1,po) ;
    bfs(heights,visited2,ao) ;
    for (int i = 0 ; i<n ; i++)
        for (int j = 0 ; j<m ; j++)
            if (visited1[i][j] && visited2[i][j])
                ans.push_back({i,j}) ;
    return ans ;  
}
};