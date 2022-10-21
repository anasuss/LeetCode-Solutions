class Solution {
public:
    vector<int> v ; 
    vector<vector<int>> ans ;
    bitset<101> bs ; 
    int x ; 
    void work(vector<int>&candidates , int target , int i = 0 ){
        if (target == 0){
            ans.push_back(v) ; 
            return ; 
        }
        if (i == candidates.size())
            return ; 
        if (candidates[i]>target)
            return ; 
        if (x != -1 && candidates[i] == x){
            work(candidates,target,i+1) ;
            return ; 
        }
        if (candidates[i]<=target && !bs[i]){
            v.push_back(candidates[i]) ; 
            bs[i] = true ; 
            work(candidates,target-candidates[i],i+1) ;
            bs[i] = false ;
            x = v.back() ; 
            v.pop_back() ; 
        } 
        work(candidates,target,i+1) ;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        work(candidates,target) ; 
        return ans; 
    }
};