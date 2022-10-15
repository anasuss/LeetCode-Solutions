class Solution {
public:
    int dx[4] = {1,-1,0,0} ; 
    int dy[4] = {0,0,1,-1} ;  
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size() ; 
        int m = mat[0].size() ; 
        for (int i = 0 ; i<n ; i++){
            int l = 0 , r = m-1 ; 
            while(l<=r){
                int mid = l+(r-l)/2 ;
                int val = mat[i][mid] ;
                bool check = true ; 
                for (int j = 0 ; j<4 ; j++){
                    int x = i+dx[j] ; 
                    int y = mid+dy[j] ; 
                    if (x<0 || y<0 || x>=n || y>=m)
                        continue ; 
                    if (val<mat[x][y]){
                        check = false ; 
                        break ; 
                    }
                }
                if (check)
                    return {i,mid} ; 
                if (mid+1<m && val<mat[i][mid+1])
                    l = mid+1 ; 
                else 
                    r = mid-1 ; 
            }
        }
        return{1,1} ; 
    }
};