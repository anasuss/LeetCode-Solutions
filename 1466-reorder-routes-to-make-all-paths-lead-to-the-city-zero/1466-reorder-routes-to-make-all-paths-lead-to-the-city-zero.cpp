class Solution {
public:
unordered_map<int,unordered_set<int>>graph_directed  ;

vector<vector<int>> graph_undirected ;

vector<bool> visited ;

int m = 0 ;

void dfs(int node){
    if (visited[node])
        return ;
    visited[node] = true ;
    for (int child : graph_undirected[node]){
        if (!visited[child]){
        auto it = graph_directed[child].find(node) ;
        if (it == graph_directed[child].end()){
            graph_directed[child].insert(node) ;
            //graph_directed[node].erase(child) ;
            ++m ;
        }
        dfs(child);
        }
    }
}
int minReorder(int n, vector<vector<int>>& connections) {
    graph_directed.clear() ;
    graph_undirected.resize(n) ;
    visited.resize(n) ;
      for (int i = 0 ; i<(int)connections.size() ; i++){
            int from , to ;
            from = connections[i][0]  ;
            to = connections[i][1] ;
            graph_directed[from].insert(to) ;
            graph_undirected[from].push_back(to) ;
            graph_undirected[to].push_back(from) ;
      }
        m = 0 ;
        dfs(0) ;
    return m ;
}
};