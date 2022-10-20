class Solution {
public:
    vector<int> v ; 
    vector<vector<int>> ans ; 
    void work(vector<int>&candidates , int target , int i = 0 , int s = 0){
        if (s == target){
            ans.push_back(v) ; 
            return ; 
        }
        if (i == candidates.size())
            return ; 
        if (s+candidates[i]<=target){
            v.push_back(candidates[i]) ; 
            work(candidates,target,i,s+candidates[i]) ; 
            v.pop_back() ; 
        }
        work(candidates,target,i+1,s) ; 
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        work(candidates,target) ; 
        return ans; 
    }
};