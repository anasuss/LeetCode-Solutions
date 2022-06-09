class Solution {
public:
  
vector<int> color ;

bool v = false ;

void dfs(int node , vector<vector<int>>& graph , int c = 1){

    if (color[node] == 0){
        color[node] = c ;
    }
    else{
        if (color[node] != c)
            v = true ;
        return ;
    }
    for (int child : graph[node]){
        if (!v)
        dfs(child,graph,3-c);
    }
}
bool isBipartite(vector<vector<int>>& graph) {
    color.resize(graph.size()) ;
    for (int i = 0 ; i<graph.size() ; i++){
        if (color[i] == 0){
            v = false ; 
            dfs(i,graph) ;
            if (v)
                return false ;
        }
    }
    return true ;
}
};