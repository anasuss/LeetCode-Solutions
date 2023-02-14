//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    int n ;
    vector<int> ans ; 
    vector<int> visited ; 
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[],int node){
        visited[node] = true ;
        ans.push_back(node);
        for (int child : adj[node]){
            if (!visited[child]){
                dfs(adj,child) ; 
            }
        }
        return ; 
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        n = V ; 
        visited.resize(n,false) ; 
        for (int i = 0 ; i<n ; i++){
            if (!visited[i]){
                dfs(adj,i) ; 
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends