//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int dx[4] = {0,1,-1,0} ; 
        int dy[4] = {-1,0,0,1} ; 
        int n = grid.size() ; 
        int m = grid[0].size() ; 
        vector<vector<bool>> visited(n,vector<bool>(m)) ;
        queue<pair<int,int>> q ; 
        int ans = 0 ; 
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                if (grid[i][j] == 0 || grid[i][j] == 2)
                    visited[i][j] = true ; 
                if (grid[i][j] == 2){
                    q.push({i,j}) ; 
                }
            }
        }
        
        for (int level = 0 , sz = q.size() ; !q.empty() ; level++ , sz = q.size()){
            while(sz--){
                int x = q.front().first ; 
                int y = q.front().second ;
                q.pop() ; 
                for (int i = 0 ; i<4 ; i++){
                    int nx = x+dx[i] ; 
                    int ny = y+dy[i] ; 
                    if (nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny]){
                        visited[nx][ny] = true ; 
                        q.push({nx,ny}) ; 
                    }
                }
            }
            if (q.empty())
                ans = level ; 
        }
        for(int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                if (!visited[i][j]){
                    return -1 ; 
                }
            }
        }
        return ans ; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends