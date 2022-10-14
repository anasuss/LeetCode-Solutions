class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size()-1 ;
        if (n == 0)
            return a[0] ; 
        int l = 0 , r = n ; 
        while(l<=r){
            int mid = l+(r-l)/2 ; 
            if (mid == 0 && a[mid] != a[mid+1])
                return a[mid] ; 
            else if (mid == n && a[mid] != a[mid-1])
                return a[mid] ; 
            else if (a[mid] != a[mid-1] && a[mid] != a[mid+1])
                return a[mid] ; 
            if (mid>0 && a[mid] != a[mid-1] && mid%2 == 0)
                l = mid+1 ; 
            else if (mid>0 && a[mid] == a[mid-1] && mid%2 == 1)
                l = mid+1 ; 
            else 
                r = mid-1 ; 
        }
        return 0 ; 
    }
};