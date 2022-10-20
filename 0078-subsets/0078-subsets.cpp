class Solution {
public:
    vector<vector<int>> ans ;
    vector<int> v ; 
    void work(vector<int>&nums , int i = 0 ){
        if (i == nums.size()){
            ans.push_back(v) ; 
            return ; 
        }
        work(nums,i+1) ; 
        v.push_back(nums[i]) ; 
        work(nums,i+1) ; 
        v.pop_back() ; 
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        work(nums) ; 
        return ans ; 
    }
};