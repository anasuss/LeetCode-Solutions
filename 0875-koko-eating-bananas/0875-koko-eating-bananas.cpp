class Solution {
public:
    bool possible(int mid , vector<int>&piles , int h){
        long long k = 0 ; 
        for (int i = 0 ; i<piles.size() ; i++){
            int x = ceil((double)piles[i]/(double)mid) ; 
            k+=x ; 
        }
        return k<=h ; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1 , r = 1e9 ; 
        while(l<=r){
            long long mid = l+(r-l)/2 ; 
            if (possible(mid,piles,h))
                r = mid-1 ; 
            else 
                l = mid+1 ; 
        }
        return r+1 ; 
    }
};