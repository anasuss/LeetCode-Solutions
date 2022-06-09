class Solution {
public:
   unordered_map<int,vector<int> > graph ;
unordered_set<int> visited ;
void dfs(int node , vector<int> &ans){
    if (visited.count(node) != 0)
        return ;
    visited.insert(node) ;
    ans.push_back(node) ;
    for (int i = 0 ; i<graph[node].size() ; i++)
        dfs(graph[node][i],ans) ;
}
vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
      vector<int> ans ;
      graph.clear() ; 
      visited.clear() ; 
      for (int i = 0 ; i<adjacentPairs.size() ; i++){
          int nd1 = adjacentPairs[i][0] ;
          int nd2 = adjacentPairs[i][1] ;
          graph[nd1].push_back(nd2) ;
          graph[nd2].push_back(nd1);
      }
      int node = 0 ;
      for (auto it = graph.begin() ; it!= graph.end() ; it++){
            if (graph[it->first].size() == 1){
                node = it->first ;
                break ;
            }
      }
      dfs(node,ans) ;
    return ans ;
}
};