class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size()-1 ;
        if (n == 0){
            return n ; 
        }
        if (nums[0]>nums[1])
            return 0 ; 
        if (nums[n]>nums[n-1])
            return n ; 
        int l = 1 , r = n-1 ; 
        while(l<=r){
            int mid = l+(r-l)/2 ; 
            if (nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid ; 
            }
            if (nums[mid-1]>nums[mid])
                r = mid-1 ; 
            else 
                l = mid+1 ; 
        }
        return 0 ; 
    }
};