class Solution {
public:
    bool canJump(vector<int>& nums) {
        queue<int> q ; 
        if (nums.size() == 1)
            return true ; 
        if (nums[0] == 0)
            return false ; 
        for (int i = 0 ; i<nums.size() ; i++){
            if (nums[i] == 0)
                q.push(i) ; 
        }
        if (q.size() == 0)
            return true ; 
        for (int i = 0 ; i<nums.size() ; i++){ 
            int idx = i+nums[i] ;
            if (idx>=nums.size()-1)
                return true ;
            while(q.size()>0 && idx>q.front())
                q.pop() ; 
            if (q.size()>0 && i>=q.front())
                return false ; 
        }
        return q.size() == 0; 
    }
};