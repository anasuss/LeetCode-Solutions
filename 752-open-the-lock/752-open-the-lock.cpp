class Solution {
public:
int openLock(vector<string>& deadends, string target) {
    queue<string> q ;
    unordered_set<string> visited ;
    q.push("0000") ;
    visited.insert("0000") ;
    if (find(deadends.begin(),deadends.end(),"0000") != deadends.end())
            return -1 ;
    for (int level = 0 , sz = 1 ; !q.empty() ; level++ , sz = q.size()){
        while(sz--){
            string s = q.front() ;
            q.pop() ;
             if (s == target)
                return level ; 
             if (find(deadends.begin(),deadends.end(),s) != deadends.end())
                continue;
            string sn = s ;
            for (int j = 0 ; j<4 ; j++){
                int n = s[j]-'0' ;
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
            sn = s ;
         }
        }
    }
    return -1 ; 
}
};