class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans = INT_MAX ;
        int mn = INT_MAX ;
        set<int> s ;
        for (int i = 0 ; i<nums.size() ; i++)
            if(nums[i]%2 == 1)
                nums[i]*=2 ;
        for (int i = 0 ; i<nums.size() ; i++){
            s.insert(-nums[i]) ;
            mn = min(mn,nums[i]) ;
        }
        while(1){
            int p = -(*s.begin());
            s.erase(s.begin()) ;
             ans = min(ans,p-mn) ;
            if (p%2)
                break ;
            p/=2 ;
            mn = min(mn,p) ;
            s.insert(-p) ;
        }
        return ans ; 
    }
};