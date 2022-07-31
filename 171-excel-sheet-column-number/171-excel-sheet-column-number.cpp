class Solution {
public:
    int titleToNumber(string columnTitle) {
           int ans = 0 ;
        for (int i = 0 ; i<columnTitle.size() ; i++){
            int a = (columnTitle[i]-'A'+1) ;
            ans+=pow(26,columnTitle.size()-i-1)*a ;
        }
       return ans ; 
    }
};