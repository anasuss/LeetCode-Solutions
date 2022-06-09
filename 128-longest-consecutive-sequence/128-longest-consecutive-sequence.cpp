class Solution {
public:
unordered_map<int,vector<int> > graph ;


unordered_map<int,int> mp ;

int cnt = 0 ;

void dfs(int node ){
    ++cnt ;
    for (int i = 0 ; i<graph[node].size() ; i++)
        dfs(graph[node][i]);

}
int longestConsecutive(vector<int>& nums) {
     graph.clear() ;
     mp.clear() ;
     for (int i = 0 ; i<nums.size() ; i++){
         ++mp[nums[i]];
     }
     for (auto it = mp.begin() ; it!=mp.end() ; it++){
        int x = it->first ;
        if (mp.find(x+1) != mp.end()){
            graph[x].push_back(x+1) ;
        }
     }

     int ans = 0 ;
     for (auto it = mp.begin() ; it!=mp.end() ; it++){
            int x = it->first ;
            if (mp.find(x-1) == mp.end()){
                cnt = 0 ;
                dfs(x);
                ans = max(ans,cnt) ;
            }
     }
     return ans ;
}
};