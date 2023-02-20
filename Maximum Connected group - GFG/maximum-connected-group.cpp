//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n+1) ; 
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1 ; 
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u] ; 
        }
        else{
            parent[ulp_v] = ulp_u ;
            size[ulp_u]+=size[ulp_v] ; 
        }
    }
};

class Solution {
  private:
    bool isValide(int x , int y , int n , int m){
        return x>=0 && y>=0 && x<n && y<m ; 
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size() ; 
        int m = grid[0].size() ;
        vector<vector<bool>> visited(n,vector<bool>(m,false)) ; 
        DisjointSet ds(n*m) ; 
        int dx[4] = {0,1,-1,0} ; 
        int dy[4] = {-1,0,0,1} ; 
        for (int i = 0 ; i<n ; i++)
            for (int j = 0 ; j<m ; j++){
                   if (grid[i][j]){
                       visited[i][j] = true ; 
                       for (int k = 0 ; k<4 ; k++){
                           int x = i+dx[k] ; 
                           int y = j+dy[k] ;
                           if (!isValide(x,y,n,m) || !grid[x][y] || visited[x][y])
                            continue ; 
                           int nodeA = i*m+j ; 
                           int nodeB = x*m+y ;
                           ds.unionByRank(nodeA,nodeB) ; 
                       }
                   }
            }
        int ans = 0 ; 
        for (int i = 0 ; i<n*m ; i++){
            ans = max(ans,ds.size[i]) ; 
        }
        set<int> s ; 
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                if (!grid[i][j]){
                    s.clear() ; 
                    for (int k = 0 ; k<4 ; k++){
                        int x = i+dx[k] ;
                        int y = j+dy[k]; 
                        if (!isValide(x,y,n,m) || !grid[x][y])
                            continue ; 
                        s.insert(ds.findUPar(x*m+y)) ; 
                    }
                    int sum = 0 ; 
                    for (auto it : s)
                        sum+=ds.size[it] ; 
                    ans = max(ans,sum+1) ; 
                }
            }
        }
        return ans ; 
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends