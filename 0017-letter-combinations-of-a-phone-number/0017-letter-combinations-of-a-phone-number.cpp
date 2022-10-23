class Solution {
public:
    vector<vector<char>> map = {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    vector<string> ans ;
    void work(string& dg , int i = 0 , string s = ""){
        if (i == dg.size()){
            ans.push_back(s) ; 
            return ; 
        }
        int x = dg[i]-'0'-2 ;
        for (char c : map[x]){
            work(dg,i+1,s+c) ; 
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == ""){
            return {} ; 
        }
        work(digits) ; 
        return ans ; 
    }
};