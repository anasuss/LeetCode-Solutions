class Solution {
public:
    typedef long long ll ; 
    
    bool is_possible(int mid , vector<int>&v , int x){
        ll sum = 0 ; 
        for (int i = 0 ; i<v.size() ; i++){
            ll y = ceil((double)v[i]/(double)mid) ; 
            sum+=y; 
            if (sum>x)
                return false ;  
        }
        return true ; 
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1 , r = *max_element(nums.begin(),nums.end()) ; 
        while(l<=r){
            int mid = l+(r-l)/2 ; 
            if (is_possible(mid,nums,threshold))
                r = mid-1 ; 
            else 
                l = mid+1 ; 
        }
        return r+1 ; 
    }
};