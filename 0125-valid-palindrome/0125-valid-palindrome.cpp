class Solution {
public:
    bool isPalindrome(string s){ 
        string sn = "" ; 
        for (int i = 0 ; i<s.size() ; i++){
            s[i] = tolower(s[i]) ; 
            if (isalpha(s[i]) || (s[i]>='0' && s[i]<='9'))
                sn+=s[i] ; 
        }
        if (sn.size() == 0)
            return true ; 
        int i = 0 , j = sn.size()-1 ; 
        while(i<j){
            if (sn[i] != sn[j]) return false ;
            ++i , --j ; 
        }
        return true ; 
    }
};