class Solution {
public:
    vector<string> v ; 
void work(int n , string &s , int cnt = 0){
 
    if (s.size() == 2*n ){
        if (cnt != 0)
            return ; 
        v.push_back(s) ; 
        return ;
    }
    s.push_back('(') ; 
    work(n,s,cnt+1) ;
    s.pop_back() ; 
    if (cnt>0){
        s.push_back(')') ; 
        work(n,s,cnt-1) ;
        s.pop_back() ; 
    }
}
    vector<string> generateParenthesis(int n) {
        string s = "" ; 
        work(n,s) ; 
        return v ; 
    }
};