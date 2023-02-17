//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private :
    int dx[8] = {0,1,-1,0,1,-1,1,-1} ; 
    int dy[8] = {1,0,0,-1,1,1,-1,-1} ; 
    int n , m ; 
    
  public:
    // Function to find the number of islands
    void dfs(vector<vector<char>>&grid,int x , int y){
        grid[x][y] = '0' ; 
        for (int i = 0 ; i<8 ; i++){
            int nx = x+dx[i] ; 
            int ny = y+dy[i] ; 
            if (nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny] == '1')
                dfs(grid,nx,ny) ; 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        n = grid.size() ; 
        m = grid[0].size() ; 
        int ans = 0 ; 
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                if (grid[i][j] == '1'){
                    dfs(grid,i,j) ; 
                    ++ans ; 
                }
            }
        }
        return ans; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends