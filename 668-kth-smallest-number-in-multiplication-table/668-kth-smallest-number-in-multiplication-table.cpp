class Solution {
public:
    int Number_less_than_me(int n , int m ,int mid){
    int cnt = 0 ;
    for (int i = 1 ; i<=n ; i++)
        cnt+=min(mid/i,m) ;
    return cnt ;
}
    int findKthNumber(int m, int n, int k) {
          int l = 0 , r =n*m;
         int kth=-1 ;
            while(r>=l){
             int mid = l+(r-l)/2 ;
        if (Number_less_than_me(n,m,mid)<k)
            l = mid+1 ;
        else
           r = mid-1 , kth = mid ;
    }
    return kth ;
    }
};