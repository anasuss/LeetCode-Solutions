class Solution {
public:
    vector<int> v ; 
    vector<vector<int>> ans ;
    bitset<101> bs ; 
    int x ; 
    void work(vector<int>&candidates , int target , int idx = 0 ){
        if (target == 0){
            ans.push_back(v) ; 
            return ; 
        }
        for (int i = idx ; i<candidates.size() ; i++){
            if (i>idx && candidates[i] == candidates[i-1])
                continue ; 
            if (candidates[i]>target) break ;
            v.push_back(candidates[i]) ; 
            work(candidates,target-candidates[i],i+1) ;
            v.pop_back() ; 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        work(candidates,target) ; 
        return ans; 
    }
};