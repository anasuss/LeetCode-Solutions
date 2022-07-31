class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp ;
     int ans = 0 ;
     int a = nums.size()/2 ;
         for (int i = 0 ; i<nums.size() ; i++){
            mp[nums[i]]++ ;
            if (mp[nums[i]]>a){
              ans = nums[i] ;
              break ;
            }
          }
    return ans ;
    }
};