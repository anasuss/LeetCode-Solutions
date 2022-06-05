class Solution {
public:

 bool possible(int mid , vector<int>& nums, int threshold){
   long long sum = 0 ;
   for(int i = 0 ; i<(int)nums.size() ; i++){
        int x = (int)nums[i]/mid ;
        if ((double)nums[i]/mid>x)
            x+=1;
        sum+=x ;
   }
   return sum<=threshold ;
}


int smallestDivisor(vector<int>& nums, int threshold){
    int ans = 0 ;
    int r = 0 , l = 1 ;
    for (int i = 0 ; i<nums.size() ; i++)
        r = max(r,nums[i]) ;

    while(r>=l){
        int mid = l + (r-l)/2 ;
        if (possible(mid,nums,threshold))
            r = mid-1 , ans = mid ;
        else
            l = mid+1 ;
    }
  return ans ;
}

};