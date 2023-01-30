//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        // Write your Code here
        vector<int> v ; 
        for (int i = 0 ; i<str1.size() ; i++){
            if (str1[i] == str2[0]){
                v.push_back(i) ; 
            }
        }
        int length = INT_MAX ; 
        int start = 0 ; 
        for(int p : v){
            int k = 1 ;
            int j = p+1 ; 
            for (; j<str1.size() && k<str2.size() ; j++){
                if (str1[j] == str2[k]){
                    ++k ; 
                }
            }
            if (k < str2.size() && length == INT_MAX){
                return "" ;
            }
            if (j-p<length && k == str2.size()){
                start = p ;
                length = j-p ;
            }
        }
        return str1.substr(start,length) ; 
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends