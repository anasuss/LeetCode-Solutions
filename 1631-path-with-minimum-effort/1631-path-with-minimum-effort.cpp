class Solution {
public:

bool visited[100][100] ;

int dx[4] = {-1,0,1,0} ;

int dy[4] = {0,-1,0,1} ;

int n , m ;

int ans = INT_MAX ;

bool isvalide(int r , int c){
    return r<n && c<m && r>=0 && c>=0 && !visited[r][c] ;
}

bool dfs(vector<vector<int>>& heights,int limit,int r = 0 , int c = 0){

    if (r == n-1 && c == m-1){
        return true ;
    }

    visited[r][c] = true ;

    for (int i = 0 ; i<4 ; i++){
        int x = r+dx[i] ;
        int y = c+dy[i] ;
        if (isvalide(x,y) && abs(heights[x][y]-heights[r][c])<=limit)
           if (dfs(heights,limit,x,y)) return true ;
    }
    return false ;
}
bool is_possible(vector<vector<int>>& heights,int limit){
    memset(visited,false,sizeof(visited));
    return dfs(heights,limit) ;
}
int minimumEffortPath(vector<vector<int>>& heights) {
      n = (int)heights.size() ;
      m = (int)heights[0].size() ;
      int s = 0 ,  e = 1e6 ;
      while(e>=s){
        int mid =s+(e-s)/2 ;
        if(is_possible(heights,mid))
            e = mid-1 , ans = mid;
        else
            s = mid+1 ;
      }
      return ans ;
}
};