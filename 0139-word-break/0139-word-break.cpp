class Solution {
public:

unordered_map<string,int> dp ;  
bool is_Same(string &a , string b){
    if (b.size()>a.size())
        return false ;
    for (int i = 0 ; i<(int)b.size() ; i++)
        if (a[i] != b[i])
            return false ;
    return true ;
}

int wordBrea(string &A, vector<string> &B , string s = "" ) {
        //code here
    if (s == A)
        return dp[s] = true ;
    
    if (dp.find(s) != dp.end())
        return dp[s] ; 
    
    for (int i = 0 ; i<B.size() ; i++){
        if ( is_Same(A,s+B[i]) && wordBrea(A,B,s+B[i]) )
          return dp[s] = true ; 
    }
    return dp[s] = false ; 
}
int wordBreak(string &A, vector<string> &B ) {
    dp.clear() ; 
    return wordBrea(A,B) ; 
}
};