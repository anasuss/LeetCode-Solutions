class Solution {
public:
bool bfs(int node , vector<int> &arr, bool visited[]){
    int n = (int)arr.size() ;
    queue<int> q ;
    q.push(node) ;
    if (arr[node] == 0)
        return true ;
    visited[node] = true ;
    while(!q.empty()){
        node = q.front() ;
        q.pop() ;
        if (arr[node]+node<n && !visited[node+arr[node]])
            if (arr[arr[node]+node] == 0)
                return true ;
            else
                q.push(arr[node]+node) ;

        if (node-arr[node]>=0 && !visited[node-arr[node]])
            if (arr[node-arr[node]] == 0)
                return true ;
            else
                q.push(node-arr[node]) ;
        if (arr[node]+node<n)
            visited[arr[node]+node] = true ;
        if (node-arr[node]>=0)
            visited[node-arr[node]]= true ;
    }

    return false ;
}

bool canReach(vector<int>& arr, int start) {
    int n = (int)arr.size() ;
    bool visited[n] ;
    memset(visited,false,sizeof(visited));
    return bfs(start,arr,visited) ;
}


};