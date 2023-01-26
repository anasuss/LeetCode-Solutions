//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string &s) {
        // Code here
        int n = s.size() ; 
        int l = 0 , ans = 0; 
        int freq[3] ; 
        memset(freq,0,sizeof(freq)) ; 
        for (int r = 0 ; r<n ; r++){
            freq[s[r]-'a']++ ; 
            while(freq[0] && freq[1] && freq[2]){
                ans+=(n-r);
                --freq[s[l]-'a'] ; 
                ++l ; 
            }
        }
        return ans; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends