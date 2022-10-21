class Solution {
public:
    vector<vector<int>> ans ; 
    vector<int> v ; 
    void work(vector<int>&nums , int idx = 0){
        ans.push_back(v) ; 
        for (int i = idx ; i<nums.size() ; i++){
            if (i>idx && nums[i] == nums[i-1])
                continue ; 
            v.push_back(nums[i]) ; 
            work(nums,i+1) ; 
            v.pop_back() ; 
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ; 
        work(nums) ; 
        return ans ;
    }
};