class Solution {
public:
int openLock(vector<string>& deadends, string target) {
    queue<string> q ;
    unordered_set<string> visited ;
    for (string s : deadends)
        if (s == "0000")
            return -1 ; 
        else 
            visited.insert(s) ; 
    q.push("0000") ;
    visited.insert("0000") ;
    if (target == "0000")
        return 0 ; 
    for (int level = 0 , sz = 1 ; !q.empty() ; level++ , sz = q.size()){
        while(sz--){
            string sn = q.front() ;
            q.pop() ;   
            for (int j = 0 ; j<4 ; j++){
                char c = sn[j] ; 
                int n = sn[j]-'0' ;
                int x = (n+1)%10 ;
                sn[j] = char(x+'0') ;
                if (sn == target)
                    return level+1 ;
                if (visited.count(sn) == 0){
                    visited.insert(sn) ;
                    q.push(sn) ;
                }
                x = n-1 ;
                if (x == -1)
                x = 9 ;
                sn[j] = char(x+'0') ;
                if (sn == target)
                    return level+1 ;
                if (visited.count(sn) == 0){
                    visited.insert(sn) ;
                    q.push(sn) ;
                }
            sn[j] = c;
         }
        }
    }
    return -1 ; 
}
};