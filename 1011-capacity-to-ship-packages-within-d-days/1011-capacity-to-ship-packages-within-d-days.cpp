class Solution {
public:
    bool is_possible(vector<int>& weights, int days , int mid){
        int sum = 0 ;
        int d = 1 ;
        int n = weights.size() ;
        for(int i = 0 ; i<n ; i++){
            sum+=weights[i] ;
            if (i == n-1 && sum == mid)
                return true ; 
            if (sum >= mid){
                ++d ; 
                if (sum == mid)
                    sum = 0 ; 
                else 
                    sum = weights[i] ; 
                if (d>days || sum>mid)
                    return false ; 
            }
        }
        return true ; 
    }
     

    int shipWithinDays(vector<int>& weights, int days){
        int s = accumulate(weights.begin(),weights.end(),0) ; 
        int l = 1 , r = s ; 
        while(l<r){
            int mid = l+(r-l)/2 ; 
            if (is_possible(weights,days,mid))
                r = mid ; 
            else 
                l = mid+1 ; 
        }
        return r ; 
    }
};