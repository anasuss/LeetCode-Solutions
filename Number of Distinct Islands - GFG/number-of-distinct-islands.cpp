//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    int dx[4] = {1,-1,0,0} ; 
    int dy[4] = {0,0,1,-1} ;
    vector<pair<int,int>> v ; 
    int n , m ; 
    void dfs(vector<vector<int>>& grid,int x , int y , int xx , int yy){
        grid[x][y] = 0 ; 
        v.push_back({x-xx,y-yy}); 
        for (int i = 0 ; i<4 ; i++){
            int nx = x+dx[i] ; 
            int ny = y+dy[i] ; 
            if (nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]){
                dfs(grid,nx,ny,xx,yy) ; 
            }
        }
        return ; 
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        n = grid.size() ; 
        m = grid[0].size() ; 
        set<vector<pair<int,int>>> st ; 
        for (int i = 0 ; i<n ; i++)
            for (int j = 0 ; j<m ; j++)
                if (grid[i][j]){
                    v.clear() ; 
                    dfs(grid,i,j,i,j) ; 
                    st.insert(v)  ;
                }
        return st.size() ; 
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends