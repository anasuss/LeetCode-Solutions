//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string &s, int k) {
        // code here
        int n = s.size() ; 
        char c = s[0] ; 
        int l = 0 ; 
        int ans = 0 ; 
        int freq[26] ;
        memset(freq,0,sizeof(freq)) ;
        for (int r = 0 ; r<n ; r++){
            freq[s[r]-'A']++ ;
            int mx = 0 ; 
            for (int i = 0 ; i<26 ; i++){
                mx=max(mx,freq[i]) ; 
            }
            if (r-l+1-mx>k){
                freq[s[l]-'A']-- ;
                ++l ; 
            }
            ans = max(ans,r-l+1) ;
        }
        return ans; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends