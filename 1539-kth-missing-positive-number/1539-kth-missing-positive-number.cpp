class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size() ; 
        k -=(arr[0]-1) ; 
        if (k == 0){
            return arr[0]-1 ; 
        }
        if (k<0){
            return arr[0]-1+k ; 
        }
        for (int i = 0 ; i<n-1 ; i++){
            if (arr[i]+1 != arr[i+1])
                k-=(arr[i+1]-arr[i]-1) ;
            if (k == 0)
                return arr[i+1]-1 ; 
            if (k<0){
                arr[i+1]+=k ; 
                return arr[i+1]-1 ; 
            }
        }
        return arr[n-1]+k;
    }
};