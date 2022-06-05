class Solution {
public:
  bool possible(vector<int>& houses, vector<int>& heaters , int dist){
    int l ,  r ;
    int j = 0 ;
    for (int i = 0 ; i<heaters.size() ; i++){
        l = heaters[i]-dist ;
        r = heaters[i]+dist ;
        while (j<houses.size() && l<=houses[j] && r>=houses[j]) ++j ;
     }
     return j == houses.size() ;
}

int findRadius(vector<int>& houses, vector<int>& heaters){

    int l = 0 ,   r = 1e9  ;
    int ans = -1 ;
    sort(houses.begin(),houses.end()) ;
    sort(heaters.begin(),heaters.end());
    while (r>=l){
        int mid = l+(r-l)/2 ;
        if (possible(houses,heaters,mid))
            r = mid-1 , ans = mid ;
        else
            l = mid+1;
    }
    return ans ;
}



};