class Solution {
public:
    int binary_ser(vector<int>& a , int l , int r , int target){
        while(l<=r){
            int mid = l+(r-l)/2 ;
            if (a[mid] == target)
                return mid ;
            if (a[mid]>target)
                r = mid-1 ;
            else
                l = mid+1 ;
        }
        return -1 ;
    }
    int search(vector<int>& a, int target) {
        int l = 1 ,r = a.size()-1 ;
        int k = 0 ;
        while(l<=r){
            int mid = l+(r-l)/2 ;
            if (a[mid]>a[0])
                l = mid+1 ;
            else
                r = mid-1 , k = mid ;
        }
        int x = binary_ser(a,0,k-1,target) ;
        int y = binary_ser(a,k,a.size()-1,target) ;
        if (x == -1 && y == -1)
            return -1 ; 
        else 
            return max(x,y) ;         
    }
};