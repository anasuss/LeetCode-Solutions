//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& arr, int target) {
        // Code here
        for (int i = 0 ; i<n ; i++)
            arr[i] = arr[i]%2 ; 
        int l = 0 ; 
        int nb = 0 ; 
        int ans = 0 ;
        int s = 0; 
        for (int r = 0 ; r<n ; r++){
            s+=arr[r] ; 
            if (s<target)
                continue ; 
            if (s>target){
                while(s>target){
                    s-=arr[l] ; 
                    ++l ; 
                    ans+=nb ; 
                }
                nb = 0 ; 
            }
            ++nb ; 
        }
        while(arr[l] == 0)
            ans+=nb , l+=1 ; 
        return ans+nb ; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends