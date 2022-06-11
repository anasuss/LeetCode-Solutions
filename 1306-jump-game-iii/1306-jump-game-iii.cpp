class Solution {
public:
vector<vector<int> > graph ;


bool bfs(int node , vector<int> &arr, bool visited[]){
    queue<int> q ;
    q.push(node) ;
    if (arr[node] == 0)
        return true ;
    visited[node] = true ;
    while(!q.empty()){
        node = q.front() ;
        q.pop() ;
        for(int neighbor : graph[node]){
            if (!visited[neighbor]){
                visited[neighbor] = true ;
                q.push(neighbor) ;
                if (arr[neighbor] == 0)
                    return true ;
            }
        }
    }

    return false ;
}

bool canReach(vector<int>& arr, int start) {
    int n = (int)arr.size() ;
    bool visited[n] ;
    memset(visited,false,sizeof(visited));
    graph.clear() ;
    graph.resize(n) ;
    for (int i = 0 ; i<n ; i++){
        int to1 = arr[i]+i ;
        int to2 = i-arr[i] ;
        if (to1>=0 && to1<n){
            graph[i].push_back(to1) ;
        }
        if (to2>=0 && to2<n)
            graph[i].push_back(to2) ;
    }
    return bfs(start,arr,visited) ;
}

};