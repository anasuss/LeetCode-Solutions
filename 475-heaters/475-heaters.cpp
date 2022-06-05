class Solution {
public:
 int findRadius(vector<int>& houses, vector<int>& heaters){
    sort(heaters.begin(),heaters.end()) ;
    int ans = INT_MIN ;
    for (int i = 0 ; i<(int)houses.size() ; i++){
        int h = lower_bound(heaters.begin(),heaters.end(),houses[i])-heaters.begin() ;
        if (h == heaters.size()){
            ans = max(ans,abs(houses[i]-heaters[h-1])) ;
        }else if (h == 0)
             ans = max(ans,abs(houses[i]-heaters[h]));
        else{
            int best_h = min(abs(houses[i]-heaters[h]),(houses[i]-heaters[h-1])) ;
            ans = max(ans,best_h) ;
        }

    }
    return ans ;
}



};