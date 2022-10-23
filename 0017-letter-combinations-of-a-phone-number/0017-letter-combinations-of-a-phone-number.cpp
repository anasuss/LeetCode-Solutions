class Solution {
public:
    vector<vector<char>> map = {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    vector<string> ans ;
    void work(string& dg , string& s ,int i = 0){
        if (i == dg.size()){
            ans.push_back(s) ; 
            return ; 
        }
        int x = dg[i]-'2' ;
        for (char c : map[x]){
            s.push_back(c) ; 
            work(dg,s,i+1) ; 
            s.pop_back() ; 
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == ""){
            return {} ; 
        }
        string s = "" ; 
        work(digits,s) ; 
        return ans ; 
    }
};