//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private : 
    vector<int> colors ; 
    bool dfs(vector<int>adj[] , int node){
        for (int child : adj[node]){
            if (colors[child] == colors[node])
                return false ; 
            if (colors[child] == -1) {
                colors[child] = 1-colors[node] ; 
                if (!dfs(adj,child))
                    return false ; 
            }
        }
        return true ; 
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    colors.resize(V,-1) ;
	    bool ans = true ; 
	    for (int i = 0 ; i<V ; i++)
	        if (colors[i] == -1){
	            colors[i] = 1 ; 
	            ans &= dfs(adj,i) ; 
	        }
	    return ans ; 
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends