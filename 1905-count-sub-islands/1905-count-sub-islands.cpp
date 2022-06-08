class Solution {
private:
    int dx[4] = {1,-1,0,0} ;
    int dy[4] = {0,0,1,-1} ;
    vector<pair<int,int>> v ;
public:

bool isvalid(int x ,int y , int l , int c){
    return x>=0 && y>=0 && x<l && y<c  ;
}

void dfs(vector<vector<int>>& grid2,vector<vector<bool>>& visited,int l ,int c , int x,int y){
    if (visited[x][y] || grid2[x][y] == 0)
        return ;
    visited[x][y] = true ;
    v.push_back({x,y}) ;
    for (int i = 0 ; i<4 ; i++)
      if (isvalid(x+dx[i],y+dy[i],l,c))
          dfs(grid2,visited,l,c,x+dx[i],y+dy[i]) ;

}

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
     vector<vector<bool>>visited(500,vector<bool>(500,false)) ;
     int cnt = 0 ;
     int l = grid1.size() ;
     int c = grid1[0].size() ;
      v.clear(); 
     for (int i = 0 ; i<grid2.size() ;i++){
        for (int j = 0 ; j<grid2[i].size() ; j++){
            if (!visited[i][j] && grid2[i][j] == 1 && grid1[i][j] == 1){
               v.clear() ;
               dfs(grid2,visited,l,c,i,j) ;
               bool test = true ;
               for (int i = 0 ; i<v.size() ; i++){
                    int x = v[i].first ;
                    int y = v[i].second ;
                    if (grid1[x][y] != 1){
                        test = false ;
                        break ;
                    }
               }
               cnt+=test ;
            }
        }
     }
     return cnt ;
}
};