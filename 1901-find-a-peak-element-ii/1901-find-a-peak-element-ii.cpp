class Solution {
public:
    int dx[4] = {1,-1,0,0} ; 
    int dy[4] = {0,0,1,-1} ;  
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size() ; 
        int m = mat[0].size() ; 
        int l = 0 , r = n-1 ; 
        while(l<=r){
            int mid = l+(r-l)/2 ; 
            int mx = mat[mid][0] , idmx = 0 ; 
            for (int j = 1 ; j<m ; j++){
                if (mat[mid][j]>mx){
                    mx = mat[mid][j] ; 
                    idmx = j ; 
                }
            }
            bool check = true ; 
            for (int j = 0 ; j<4 ; j++){
                int x = mid+dx[j] ; 
                int y = idmx+dy[j] ; 
                if (x<0 || y<0 || x>=n || y>=m)
                    continue ; 
                if (mat[x][y]>mx){
                    check = false ;
                    break ; 
                }
            }
            if (check){
                return {mid,idmx} ; 
            }
            if (mat[mid][idmx]<mat[mid+1][idmx])
                l = mid+1 ; 
            else 
                r = mid-1 ; 
        }
        return{-1,-1} ; 
    }
};