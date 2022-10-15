class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() ; 
        int m = matrix[0].size() ; 
        for (int i = 0 ; i<n ; i++){
            int l = 0 , r = m-1 ; 
            while(l<=r){
                int mid = l+(r-l)/2 ; 
                int x = matrix[i][mid] ; 
                if (x == target)
                    return true ; 
                if (x>target)
                    r = mid-1 ; 
                else 
                    l = mid+1 ; 
            }
        }
        return false;  
    }
};