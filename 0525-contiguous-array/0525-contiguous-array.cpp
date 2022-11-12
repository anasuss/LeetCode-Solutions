class Solution {
public:
    int findMaxLength(vector<int>& a) {
        int n = a.size() ;
        unordered_map<int,int> mp ;
        int ans = 0 ; 
        for (int i = 0 ; i<n ; i++){
            if (a[i] == 0)
                a[i] = -1 ; 
            if (i>0)
                a[i]+=a[i-1] ;
            if (a[i] == 0)
                ans = i+1 ; 
        }
        for (int i = 0 ; i<n ; i++){
            if (mp.count(a[i])){
                ans = max(ans,i-mp[a[i]]) ; 
            }
            if (mp.count(a[i]) == 0)
                mp[a[i]] = i ; 
        }
        return ans ; 
    }
};