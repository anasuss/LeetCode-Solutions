class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size() ;
        int ans = 0 ; 
        unordered_map<char,pair<int,int>> mp ;
        int st = 0 ; 
        for (int i = 0 ; i<n ; i++){
            if (mp[s[i]].first != 0){
                st = max(st,mp[s[i]].second+1) ;
                mp[s[i]].first = 0 ; 
            }
            ans = max(ans,i-st+1) ; 
            mp[s[i]].first++ ;
            mp[s[i]].second = i ; 
        }
        return ans ; 
    }
};