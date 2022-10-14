class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0 ,  r = nums.size()-1 , ans = 5e3+1 ; 
        while(l<=r){
            int mid = l+(r-l)/2 ; 
            ans = min(ans,nums[mid]);
            if (nums[mid]<nums[0])
                r = mid-1 ; 
            else
                l = mid+1 ; 
        }
        return min(ans,nums[0]) ; 
    }
};