class Solution {
public:
    vector<vector<string>> ans ;
    vector<string> v ; 
    bool is_palindrome(string &s , int se , int e){
        for (int i = se ; i<=e ; i++){
            if (s[i] != s[e-(i-se)])
                return false ; 
        }
        return true;  
    }
    void work(string &s , int idx = 0){
        if (idx == s.size()){
            if (v.size() != 0){
                ans.push_back(v) ; 
            }
            return ;
        }
        for (int i = idx ; i<s.size() ; i++){
            if (is_palindrome(s,idx,i)){
                v.push_back(s.substr(idx,i-idx+1)) ; 
                work(s,i+1) ; 
                v.pop_back() ; 
            }
        }
    }
    vector<vector<string>> partition(string& s) {
        work(s) ; 
        return ans ; 
    }
};