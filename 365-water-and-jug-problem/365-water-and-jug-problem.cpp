class Solution {
public:
  bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    if (jug1Capacity+jug2Capacity<targetCapacity)
        return false ;
    if (jug1Capacity+jug2Capacity == targetCapacity)
        return true ;
    if (jug1Capacity == targetCapacity || jug2Capacity == targetCapacity)
        return true ;
    int s = max(jug1Capacity,jug2Capacity) ;
    int t = targetCapacity-min(jug1Capacity,jug2Capacity) ;
    t = abs(t) ;  
    queue<int> q ;
    q.push(0) ;
    unordered_set<int> visited ;
    visited.insert(0) ;
    while(!q.empty()){
        int neighbor = q.front() ;
        q.pop() ;
        int x = (neighbor+jug1Capacity)%jug2Capacity ;
        int y = (neighbor+jug2Capacity)%jug1Capacity ;
        if (x == t || y == t)
            return true  ;
        if (visited.insert(x).second)
            q.push(x) ;
        if (visited.insert(y).second)
            q.push(y) ;
    }

    return false ;
}
};