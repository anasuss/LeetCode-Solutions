class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size() ; 
        int l = 0 , r = n-1 ;
        while(l<=r){
            int mid = l + (r-l)/2 ; 
            int x = arr[mid]-(mid+1) ; 
            if (x<k)
                l = mid+1 ; 
            else 
                r = mid-1; 
        }
        l = min(l,n-1) ; 
        int missing = k-(arr[l]-(l+1)) ;
        if (missing>0)
            return arr[l]+missing ; 
        else 
            return arr[l]-1+missing ; 
    }
};