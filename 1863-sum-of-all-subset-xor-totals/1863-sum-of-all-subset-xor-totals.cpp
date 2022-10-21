class Solution {
public:
    vector<int> v ; 
    int ans ; 
    void work(vector<int>&nums , int i = 0){
        if (i == nums.size()){
            if (v.size() == 0)
                return  ; 
            int x = v[0] ; 
            for (int i = 1 ; i<v.size() ; i++)
                x^=v[i] ; 
            ans+=x ; 
            return  ; 
        }
        work(nums,i+1) ; 
        v.push_back(nums[i]); 
        work(nums,i+1) ;
        v.pop_back() ; 
    }
    int subsetXORSum(vector<int>& nums) {
        work(nums) ;
        return ans ; 
    }
};