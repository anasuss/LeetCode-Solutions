//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        vector<int> size , parent ; 
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int UParent(int x){
	    if (parent[x] == x)
	        return x ; 
	   return parent[x] = UParent(parent[x]) ; 
	}
	void Union(int x , int y){
	    int px = UParent(x) ; 
	    int py = UParent(y) ; 
	    if (size[px]<size[py]){
	        parent[px] = py ; 
	        size[py]+=size[px] ; 
	    }else{
	        parent[py] = px ; 
	        size[px]+=size[py] ; 
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[]){
        // code here
        size.resize(V,1) ; 
        parent.resize(V) ;
        for (int i = 0 ; i<V ; i++)
            parent[i] = i ; 
        vector<pair<int,pair<int,int>>> v ; 
        for (int i = 0 ; i<V ; i++){
            for (auto it : adj[i]){
                int x = it[0] ; 
                int w = it[1] ; 
                int y = i ; 
                v.push_back({w,{x,y}}) ; 
            }
        }
        sort(v.begin(),v.end()) ; 
        int ans = 0 ; 
        for (int i = 0 ; i<v.size() ; i++){
            int w = v[i].first ; 
            int x = v[i].second.first ; 
            int y = v[i].second.second ; 
            if (UParent(x) != UParent(y)){
                ans+=w ; 
                Union(x,y) ; 
            }
        }
        return ans ; 
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends