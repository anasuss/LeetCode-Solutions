class Solution {
public:
int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    queue<int> q ;
    long long s = 0 ;
    for (int i = 0 ; i<initialBoxes.size() ; i++){
        q.push(initialBoxes[i]) ;
    }
    unordered_set<int> boxes; 
    while(!q.empty()){
        int x = q.front() ;
        q.pop() ;
        s+=candies[x] ; 
        for(int y : containedBoxes[x]){
            if (status[y])
                q.push(y) ;
            else
              boxes.insert(y) ; 
        }
        for (int y : keys[x]){
            status[y] = 1 ; 
            if(boxes.count(y)){
                q.push(y) ; 
                boxes.erase(y) ; 
            }
        }
    }
    return s ;
    }
};