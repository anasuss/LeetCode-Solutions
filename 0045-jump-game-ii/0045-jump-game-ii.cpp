class Solution {
public:
    int jump(vector<int>& nums) {
        queue<pair<int,int>> q ; 
        q.push({0,0}) ; 
        if (nums.size() == 1)
            return 0 ; 
        if (nums.size() == 2)
            return 1 ; 
        while(!q.empty()){
            auto f = q.front() ;
            q.pop() ; 
            int parent = f.first ; 
            int dist = f.second ;
            if (parent>=nums.size()-1)
                return dist ; 
            if (parent+nums[parent]>=nums.size()-1)
                return dist+1 ;
            int mx = 0 ; 
            int idx = 0 ; 
            for (int i = 1 ; i<=nums[parent] ; i++){
                int child = parent+i ; 
                if (nums[child] != 0 && nums[child]+child>=mx){
                    mx = nums[child]+child ; 
                    idx = child ; 
                }
            }
            q.push({idx,dist+1}) ;
        }
        return -1 ; 
    }
};