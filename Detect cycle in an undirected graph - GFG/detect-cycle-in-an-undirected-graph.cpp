//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private: 
    vector<bool> visited ; 
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[],int node , int prv = -1){
        visited[node] = true ; 
        for (int &child : adj[node]){
            if (visited[child] && prv != child)
                return true ; 
            if (!visited[child] && dfs(adj,child,node)){
                return true ; 
            }
            
        }
        return false ;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        visited.resize(V,false) ; 
        bool ans = false ; 
        for (int i = 0 ; i<V ; i++){
            if (!visited[i]){
                if (dfs(adj,i))
                    ans = true ;  
            }
        }
        return ans ; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends