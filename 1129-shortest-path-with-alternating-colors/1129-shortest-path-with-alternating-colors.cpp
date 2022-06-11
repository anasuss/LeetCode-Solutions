class Solution {
public:
    struct edge{
    int node ;
    int color ;
};
 vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
  vector<vector<edge> > graph(n) ;
  //vector<bool> visited(n,false) ;
  map<int,int> visited ;
  vector<int> ans(n,-1) ;
  for (int i = 0 ; i<redEdges.size() ; i++){
        int x = redEdges[i][0] ;
        edge e ;
        e.node = redEdges[i][1] ;
        e.color = 1 ;
        graph[x].push_back(e) ;
  }
    for (int i = 0 ; i<blueEdges.size() ; i++){
        int x = blueEdges[i][0] ;
        edge e ;
        e.node = blueEdges[i][1] ;
        e.color = 2 ;
        graph[x].push_back(e) ;
    }
    queue<edge> q ;
    q.push({0,-1}) ;
    ans[0] = 0 ;
    for (int level = 0 , sz = 1 ; !q.empty() ; level++ , sz = q.size() ){
        while(sz--){
            edge x = q.front() ;
            q.pop() ;
            if (visited[x.node]>=1000)
                return ans ; 
            visited[x.node]+=1 ;
            for (edge e : graph[x.node]){
                if ((e.color == x.color && x.color != -1))
                    continue ;
               // visited[e.node]+=1 ;
                q.push(e) ;
                if (ans[e.node] == -1 )
                  ans[e.node] = level+1 ;
            }
        }
    }
     return ans ; 

}
};