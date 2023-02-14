//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private : 
    int n,m ; 
    int dx[4] = {1,0,-1,0} ; 
    int dy[4] = {0,-1,0,1} ; 
public:
    void dfs(vector<vector<int>>&grid,int x , int y){
        grid[x][y] = 0 ;
        for (int i = 0 ; i<4 ; i++){
            int nx = x+dx[i] ; 
            int ny = y+dy[i] ;
            if (nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny] == 1){
                grid[nx][ny] = 0 ;
                dfs(grid,nx,ny) ; 
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        n = grid.size() ; 
        m = grid[0].size() ;
        int ans = 0 ; 
        for (int i = 0 ; i<n ; i++){
            if (grid[i][0] == 1 ){
                dfs(grid,i,0) ; 
            }
        }
        for (int i = 0 ; i<n ; i++){
            if (grid[i][m-1] == 1){
                dfs(grid,i,m-1) ; 
            }
        }
        for (int i = 0 ; i<m ; i++){
            if (grid[0][i] == 1){
                dfs(grid,0,i) ; 
            }
        }
        for (int i = 0 ; i<m ; i++){
            if (grid[n-1][i] == 1){
                dfs(grid,n-1,i) ; 
            }
        }
        for (int i = 0 ; i<n ; i++)
            for(int j = 0 ; j<m ; j++)
                ans+=grid[i][j] ; 
        return ans ; 
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends