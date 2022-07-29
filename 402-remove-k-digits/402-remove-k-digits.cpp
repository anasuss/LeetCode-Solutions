class Solution {
public:
    string removeKdigits(string num, int k) {
     string s = "" ;
    s = num[0] ;
        for (int i = 1 ; i<num.size() ; i++){
            while (s.size() != 0 && num[i]<s[s.size()-1] && k){
                s.pop_back() ;
                k--;
            }
            s+=num[i] ;
    }
    while(s.size() != 0 && k){
            s.pop_back() ;
            k-- ;
        }
        while(s[0] == '0' && s.size()>1)
            s.erase(s.begin()) ;
        if (s.size() == 0)
            s = "0" ;
        return s ; 
    }
};