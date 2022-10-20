class Solution {
public:
    vector<string> v ; 
void work(int n , string s = "" ){
    if (s.size() == 2*n){
        int cnt = 0 ;
        for (int i = 0 ; i<s.size() ; i++){
            if (s[i] == ')')
                --cnt ;
            else
                ++cnt ;
            if (cnt<0)
                return ;
        }
        if (cnt == 0 )
            v.push_back(s) ; 
        return ;
    }
    work(n,s+"(") ;
    work(n,s+")") ;
}
    vector<string> generateParenthesis(int n) {
        work(n) ; 
        return v ; 
    }
};