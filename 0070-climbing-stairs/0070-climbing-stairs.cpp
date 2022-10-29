class Solution {
public:
    int dp[50] ; 
    int work(int n , int s = 0){
        if (dp[s] != -1)
            return dp[s] ; 
        if (s>n)
            return false ; 
        if (s == n)
            return true ; 
        return dp[s] = work(n,s+1)+work(n,s+2) ; 
    }
    int climbStairs(int n ) {
        memset(dp,-1,sizeof(dp)) ; 
        return work(n) ; 
    }
};