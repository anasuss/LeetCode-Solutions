class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0 , r = nums.size()-1 ; 
        int x = -1 , y = -1 ; 
        while(l<=r){
            int mid = l+(r-l)/2 ; 
            if (nums[mid]>=target){
                r = mid-1;
                if (nums[mid] == target)
                     x = mid ; 
            }else
                l = mid+1 ; 
        }
        if (x == -1){
            return {x,y} ; 
        }
        l = 0 , r = nums.size()-1 ; 
        while(l<=r){
            int mid = l+(r-l)/2 ; 
            if (nums[mid]>target){
                r = mid-1 ; 
            }else 
                l = mid+1 , y = mid ; 
        }
        return {x,y} ; 
    }
};