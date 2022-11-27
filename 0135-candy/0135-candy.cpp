class Solution {
public:
    int candy(vector<int>& v) {
        int n = v.size() ;
        vector<int> a(n+10,1) ;
        for (int i = 1 ; i<n  ; i++){
            if (v[i]>v[i-1])
                a[i] = a[i-1]+1 ; 
        }
        for (int i = n-1 ; i>0 ; i--){
            if (v[i-1]>v[i] && a[i]+1>a[i-1]){
                a[i-1] = a[i]+1 ; 
            }
        }
        int ans = 0 ; 
        for (int i = 0 ; i<n ; i++)
            ans+=a[i]; 
        return ans ; 
    }
};