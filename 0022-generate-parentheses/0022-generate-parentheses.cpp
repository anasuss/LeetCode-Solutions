class Solution {
public:
    vector<string> v ; 
void work(int n , string s = "" , int cnt = 0){
 
    if (s.size() == 2*n ){
        if (cnt != 0)
            return ; 
        v.push_back(s) ; 
        return ;
    }
    work(n,s+"(",cnt+1) ;
    if (cnt>0)
        work(n,s+")",cnt-1) ;
}
    vector<string> generateParenthesis(int n) {
        work(n) ; 
        return v ; 
    }
};