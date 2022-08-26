class TreeAncestor {
public:
    vector<vector<int>> graph ; 
    vector<vector<int>> up ; 
    vector<int> depth  ; 
    int log ; 
    void dfs(int node , vector<int> &parent){
        up[node][0] = parent[node] ;
        if (node>0)
            depth[node] = depth[parent[node]]+1 ; 
        for (int i = 1 ; i<log ; i++){
            up[node][i] = up[up[node][i-1]][i-1] ; 
        }
        for (int child : graph[node]){
            if (child != parent[node]){
                dfs(child,parent) ; 
            }
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        graph.resize(n);
        for (int i=0 ; i<n ; i++)
        {
            if (parent[i]!=-1)
            {
                graph[i].push_back(parent[i]);
                graph[parent[i]].push_back(i);
            }
        }
        
        log = log2(n);
        log++;
        up.resize(n, vector<int>(log));
        depth.clear();
        depth.resize(n);
        parent[0]=0;
        depth[0]=0;
        dfs(0, parent); 
    }
    
    int getKthAncestor(int node, int k) {
        if (depth[node]<k)
            return -1 ; 
        int n = log2(k) ; 
        for (int i = n ; i>=0 ; i--){
            if (k & (1<<i))
                node = up[node][i] ; 
        }
        return node ; 
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */