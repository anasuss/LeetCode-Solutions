//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private : 
    vector<vector<char>> ans ; 
    int dx[4] = {1,0,-1,0} ; 
    int dy[4] = {0,-1,0,1} ; 
public:
    void dfs(int n , int m , vector<vector<char>>&grid,int x , int y){
        for (int i = 0 ; i<4 ; i++){
            int nx = x+dx[i] ; 
            int ny = y+dy[i] ;
            if (nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny] == 'O' && ans[nx][ny] == 'X'){
                ans[nx][ny] = 'O' ;
                dfs(n,m,grid,nx,ny) ; 
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> &grid){
        // code here
        ans.resize(n,vector<char>(m,'X')) ; 
        for (int i = 0 ; i<n ; i++){
            if (grid[i][0] == 'O' ){
                ans[i][0] = 'O' ; 
                dfs(n,m,grid,i,0) ; 
            }
        }
        for (int i = 0 ; i<n ; i++){
            if (grid[i][m-1] == 'O'){
                ans[i][m-1] = 'O' ; 
                dfs(n,m,grid,i,m-1) ; 
            }
        }
        for (int i = 0 ; i<m ; i++){
            if (grid[0][i] == 'O'){
                ans[0][i] = 'O' ; 
                dfs(n,m,grid,0,i) ; 
            }
        }
        for (int i = 0 ; i<m ; i++){
            if (grid[n-1][i] == 'O'){
                ans[n-1][i] = 'O' ; 
                dfs(n,m,grid,n-1,i) ; 
            }
        }
        return ans ; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends