class Solution {
public:
    
    
vector<bool> visited ;


vector<vector<int>> graph ;


void dfs(int node , vector<int> &idx){

    if (visited[node])
        return ;

    visited[node] = true ;

    idx.push_back(node) ;

    for (int i = 0 ; i<graph[node].size() ; i++)
        dfs(graph[node][i],idx) ;

}
string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    graph.resize(s.size()) ;
    visited.resize(s.size(),false) ;
    for (int i = 0 ; i<pairs.size() ; i++){
        int x = pairs[i][0] ;
        int y = pairs[i][1] ;
        graph[x].push_back(y) ;
        graph[y].push_back(x) ;
    }
    for (int i = 0 ; i<s.size() ; i++){
        if (!visited[i]){
            vector<int> idx ;
            dfs(i,idx) ;
            string str ;
            for (int i = 0 ; i<(int)idx.size() ; i++)
                str+=s[idx[i]] ;
            sort(str.begin(),str.end() ) ;
            sort(idx.begin(),idx.end()) ;
            for (int i = 0 ; i<idx.size() ; i++)
                s[idx[i]] = str[i] ;
        }
    }

    return s ;
}
};