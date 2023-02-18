//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet d(n*m) ;
        bool visited[n][m] ; 
        int cnt = 0 ; 
        memset(visited,false,sizeof(visited)) ; 
        vector<int> ans ; 
        int dx[4] = {1,0,-1,0} ; 
        int dy[4] = {0,1,0,-1} ; 
        for (int i = 0 ; i<operators.size() ; i++){
            int x = operators[i][0] ; 
            int y = operators[i][1] ; 
            if (visited[x][y]){
                ans.push_back(cnt) ; 
                continue ; 
            }
            visited[x][y] = true ; 
            ++cnt ; 
            for (int k = 0 ; k<4 ; k++){
                int nx = x+dx[k] ; 
                int ny = y+dy[k] ; 
                if (nx>=0 && ny>=0 && nx<n && ny<m && visited[nx][ny]){
                    int nodeA = nx*m+ny ; 
                    int nodeB = x*m+y ; 
                    if (d.findUPar(nodeA) != d.findUPar(nodeB)){
                        --cnt ; 
                        d.unionBySize(nodeA,nodeB) ; 
                    }
                }
            }
            ans.push_back(cnt) ; 
        } 
        return ans ; 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends