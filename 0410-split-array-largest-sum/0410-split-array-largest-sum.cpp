class Solution {
public:
    typedef long long ll ; 
    bool possible(ll x , vector<int>&nums , int k){
        ll s = 0 ; 
        for (int i = 0 ; i<nums.size() ; i++){
            s+=nums[i] ;
            if (nums[i]>x)
                return false ; 
            if (s>x){
                s = nums[i] ; 
                --k ; 
            }
            if (s == x){
                s = 0 ; 
                --k ; 
            }
        }
        if (s != 0)
            --k ; 
        return k>=0 ; 
    }
    int splitArray(vector<int>& nums, int k) {
        ll l = 0 , r = 1000*1000000+10 ; 
       while(l<=r){
            ll mid = l+(r-l)/2 ; 
            if (possible(mid,nums,k))
                r = mid-1 ; 
            else 
                l = mid+1 ;
        }
        return (int)l ; 
    }
};