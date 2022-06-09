class Solution {
public:
unordered_set<int> visited ;


unordered_map<int,vector<int> > graph ;


unordered_map<int,int> mp ;

int cnt = 0 ;

void dfs(int node ){

    if (visited.find(node) != visited.end())
        return ;
    visited.insert(node) ;
    ++cnt ;
   // cout << cnt << endl ;
    for (int i = 0 ; i<graph[node].size() ; i++)
        dfs(graph[node][i]);

}
int longestConsecutive(vector<int>& nums) {

     graph.clear() ;
     visited.clear() ;

     for (int i = 0 ; i<nums.size() ; i++){
         ++mp[nums[i]];
     }
     for (int i = 0 ; i<nums.size() ; i++){
        int x = nums[i] ;
        if (mp.find(x+1) != mp.end()){
            graph[x].push_back(x+1) ;
            graph[x+1].push_back(x) ;
        }
     }

     int ans = 0 ;
     for (int i = 0 ; i<nums.size() ; i++){
            if (visited.find(nums[i]) == visited.end()){
                cnt = 0 ;
                dfs(nums[i]);
               // cout << cnt << endl ;
                ans = max(ans,cnt) ;
            }
     }
     return ans ;
}
};