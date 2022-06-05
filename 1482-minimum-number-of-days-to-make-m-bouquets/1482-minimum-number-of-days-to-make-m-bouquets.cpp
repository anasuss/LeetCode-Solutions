class Solution {
public:
bool possible(vector<int>& bloomDay, int m, int k , int d){
    int b = 0 ;
    int nb = 0 ;
    for (int i = 0 ; i<bloomDay.size(); i++)
        if (bloomDay[i]<=d){
            b++ ;
            if (b == k)
                ++nb , b = 0 ;
            if (nb == m )
                return true ;
        }else
            b = 0 ;
    return false ;
}

int minDays(vector<int>& bloomDay, int m, int k){

    if (m*k>bloomDay.size())
        return -1 ;
    int l = 1 ,  r = *max_element(bloomDay.begin(),bloomDay.end()) ;
    int ans = -1 ;
    while (r>=l){
        int mid = l+(r-l)/2 ;
        if (possible(bloomDay,m,k,mid))
            r = mid-1 , ans = mid ;
        else
            l = mid+1;
    }
    return ans ;
}



};