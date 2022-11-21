class Solution {
public:
    long long dp[100+10][100+10] ; 
    int m , n ; 
    long long work(vector<vector<int>>& matrix, int r , int c){
        if (r == n)
            return 0 ;
        if (c>=m || c<0 )
            return INT_MAX ; 
        if (dp[r][c] != -1)
            return dp[r][c] ; 
        long long x = work(matrix,r+1,c) ; 
        long long y = work(matrix,r+1,c+1) ; 
        long long z = work(matrix,r+1,c-1) ; 
        return dp[r][c] = matrix[r][c]+min(x,min(y,z)) ; 
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp)) ; 
        n = matrix.size() ; 
        m = matrix[0].size() ;
        long long ans = INT_MAX ;
        for (int i = 0 ; i<m ; i++){
            ans = min(ans,work(matrix,0,i)) ;
        }
        return (int)ans ; 
    }
};