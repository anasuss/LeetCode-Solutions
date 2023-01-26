//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int n, int k) {
        // code here
        int l = k-1 ; 
        int r = n-1 ; 
        int s = 0 ; 
        int ans = 0 ; 
        for (int i = 0 ; i<k ; i++)
            s+=cardPoints[i]; 
        ans = s ;
        if (k == n)
            return ans ; 
        for (int i = 0 ; i<k ; i++){
            s = s - cardPoints[l]+cardPoints[r] ; 
            ans = max(ans,s) ; 
            --l ; 
            --r ; 
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends