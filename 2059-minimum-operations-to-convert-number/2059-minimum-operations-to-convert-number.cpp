class Solution {
public:
int minimumOperations(vector<int>& nums, int start, int goal) {
    queue<int> q ;
    unordered_set<int> visited ;
    q.push(start) ;
    
    for (int level = 0 , sz = 1 ; !q.empty()  ; level++ , sz = q.size()){
        while(sz--){
            int neighbor = q.front() ;
            q.pop() ;
            for (int i = 0 ; i<nums.size() ; i++){
                    int x = neighbor-nums[i] ;
                    int y = neighbor^nums[i] ;
                    int z = neighbor+nums[i] ;
                    if (x == goal || y == goal || z == goal)
                        return level+1 ;
                    if (x>=0 && x<=1000 && visited.count(x) == 0){
                        visited.insert(x) ;
                        q.push(x) ;
                    }
                     if (y>=0 && y<=1000 && visited.count(y) == 0){
                         visited.insert(y) ;
                        q.push(y) ;
                    }
                    if (z>=0 && z<=1000 && visited.count(z) == 0){
                        visited.insert(z) ;
                        q.push(z) ;
                    }
            }
        }
    }
    return -1 ;
}

};