class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size() ; 
        int l = 0 , r = n-1 ;
        while(l<r){
            int mid = l + (r-l)/2 ; 
            int x = arr[mid]-(mid+1) ; 
            if (x<k)
                l = mid+1 ; 
            else 
                r = mid; 
        }
        int missing = k-(arr[r]-(r+1)) ;
        if (missing>0)
            return arr[r]+missing ; 
        else 
            return arr[r]-1+missing ; 
    }
};