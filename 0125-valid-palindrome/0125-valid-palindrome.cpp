class Solution {
public:
    string sn = "" ; 
    bool work(int i = 0){
        int j = sn.size()-1-i ;
        if (sn.size()%2 == 0)
            if (i+1 == j)
                if (sn[i] == sn[j])
                    return true ; 
                else 
                    return false ; 
        if (sn[i] != sn[j] || i>j)
            return false ; 
        if (i == j && sn[i] == sn[j])
            return true ;
        if (sn[i] == sn[j] && work(i+1) )
            return true ; 
        return false ; 
    }
    bool isPalindrome(string s){
        if (s.size() == 0)
            return true ; 
        for (int i = 0 ; i<s.size() ; i++){
            s[i] = tolower(s[i]) ; 
            if (isalpha(s[i]) || (s[i]>='0' && s[i]<='9'))
                sn+=s[i] ; 
        }
        if (sn.size() == 0)
            return true ; 
        return work() ; 
    }
};