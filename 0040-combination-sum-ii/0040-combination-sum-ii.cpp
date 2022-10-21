class Solution {
public:
    vector<int> v ; 
    vector<vector<int>> ans ;
    unordered_set<int> si ; 
    bitset<101> bs ; 
    void work(vector<int>&candidates , int target , int i = 0 , int x = -1){
        if (target == 0){
            ans.push_back(v) ; 
            return ; 
        }
        if (i == candidates.size())
            return ; 
        if (x != -1 && candidates[i] == x){
            work(candidates,target,i+1,x) ;
            return ; 
        }
        if (candidates[i]<=target && !bs[i]){
            v.push_back(candidates[i]) ; 
            bs[i] = true ; 
            work(candidates,target-candidates[i],i+1,x) ;
            bs[i] = false ;
            x = v.back() ; 
            v.pop_back() ; 
        } 
        work(candidates,target,i+1,x) ; 
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        work(candidates,target) ; 
        return ans; 
    }
};