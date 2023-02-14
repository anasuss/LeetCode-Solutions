//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<bool> &visited,vector<vector<int>> &adj,int node){
        visited[node] = true ; 
        for (int child = 0 ; child<adj[node].size() ; child++){
            if(child != node && adj[node][child] == 1 && !visited[child]){
                dfs(visited,adj,child) ; 
            }
        }
        return ; 
    }
    int numProvinces(vector<vector<int>> &adj, int V) {
        // code here
        int cnt = 0 ;
        vector<bool> visited(V,false) ; 
        for (int i = 0 ; i<adj.size() ; i++){
            for (int j = 0 ; j<adj[i].size() ; j++){
                if (adj[i][j] && !visited[j]){
                    ++cnt ; 
                    dfs(visited,adj,j) ; 
                }
            }
        }
        return cnt ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends