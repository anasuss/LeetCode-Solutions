//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    int dx[4] = {1,0,-1,0} ; 
    int dy[4] = {0,-1,0,1} ; 
    int n ; 
    int m ; 
public:
    void dfs(vector<vector<int>>& image, int x, int y, int newColor , int color){
        if (x<0 || y<0 || x>=n || y>=m || image[x][y] != color)
            return ; 
        image[x][y] = newColor ; 
        for (int i = 0 ; i<4 ; i++){
            int nx = x+dx[i] ; 
            int ny = y+dy[i] ; 
            dfs(image,nx,ny,newColor,color) ;
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        if (newColor == image[sr][sc]){
            return image ; 
        }
        n = image.size();  
        m = image[0].size() ; 
        dfs(image,sr,sc,newColor,image[sr][sc]) ;
        return image ; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends