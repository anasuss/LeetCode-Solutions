//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int freq[26] ; 
        memset(freq,0,sizeof(freq)) ; 
        int ans = -1 ;
        int j = 0 ; 
        for (int i = 0 ; i<s.size() ; i++){
            freq[s[i]-'a']++ ;
            if (freq[s[i]-'a'] == 1){
                --k ; 
            }
            while(k<0){
                freq[s[j]-'a']-- ; 
                if(freq[s[j]-'a'] == 0){
                    ++k ; 
                }
                ++j ; 
            }
            if (k == 0)
                ans = max(ans,i-j+1) ; 
        }
        return ans ; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends