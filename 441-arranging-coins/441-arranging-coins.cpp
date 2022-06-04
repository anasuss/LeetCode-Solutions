class Solution {
public:
  bool possible(int n , long long  r ){
    long long sum = r*(r+1)/2 ;
    return n>=sum ;
}

    int arrangeCoins(int n) {
        int ans = 0 ;
         int l = 0 , r = n ;
            while(r>=l){
                long mid = l + (r-l)/2 ;
                if (possible(n,mid))
                   l = mid+1 , ans = mid ;
                else
                    r = mid-1 ;
            }
  return ans ;
    }
};