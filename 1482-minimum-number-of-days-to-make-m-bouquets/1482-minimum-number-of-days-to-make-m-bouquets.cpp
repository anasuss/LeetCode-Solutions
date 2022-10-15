class Solution {
public:
    typedef long long ll ; 
    bool is_possible(ll maxD,vector<int>&v,int m , int k){
        int j = 0 ;
        int cnt = 0 ; 
        int mx = 0 ;
        int idxmx = 0 ; 
        for (int i = 0 ; i<v.size() ; i++){
            if (v[i]>mx){
                mx = v[i] ; 
                idxmx = i ; 
            }
            if (mx<=maxD){
                ++j ; 
                if (j == k){
                    ++cnt ; 
                    j = 0 ; 
                }
            }else{
                j = 0 ; 
                i = idxmx;
                mx = 0 ; 
                idxmx = 0 ; 
            }
        }
        return cnt>=m ; 
    }
    int minDays(vector<int>& bloomday, int m, int k) {
        ll n = bloomday.size() ;
        ll x = ll(m)*(ll)k ; 
        if (x>n)
            return -1 ; 
        ll l = 1 , r = 1e9 ; 
        while(l<=r){
            ll mid = l+(r-l)/2 ; 
            if (is_possible(mid,bloomday,m,k))
                r = mid-1 ; 
            else 
                l = mid+1 ; 
        }
        return (int)r+1 ; 
    }
};