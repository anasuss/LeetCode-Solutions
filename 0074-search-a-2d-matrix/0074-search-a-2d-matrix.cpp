class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() ; 
        int m = matrix[0].size() ;
        int l = 0 , r = n-1 ; 
        while(l<=r){
            int mid = l+(r-l)/2 ; 
            int x = matrix[mid][m-1] ; 
            if (x == target)
                return true ; 
            if (x<target)
                l = mid+1 ; 
            else 
                r = mid-1 ; 
        }
        int rw = min(l,n-1) ; 
        l = 0 , r = m-1 ; 
        while(l<=r){
            int mid = l+(r-l)/2 ; 
            int x = matrix[rw][mid] ;
            if (x == target)
                return true ; 
            if (x<target)
                l = mid+1 ; 
            else 
                r = mid-1 ; 
        }
        return false;  
    }
};