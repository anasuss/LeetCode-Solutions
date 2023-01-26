//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int n, vector<int> &fruits) {
        if (n<=2)
            return n ;
        unordered_map<int,int> mp ; 
        unordered_set<int> s ; 
        int l = 0 , ans = 0;
        for (int r = 0 ; r<n ; r++){
            mp[fruits[r]]++ ; 
            if (mp[fruits[r]] == 1){
                s.insert(fruits[r]);
                if (s.size()>2){
                    while(true){
                        mp[fruits[l]]-- ; 
                        if (mp[fruits[l]] == 0){
                            s.erase(fruits[l]) ; 
                            ++l ; 
                            break ; 
                        }
                        ++l ; 
                    }
                }
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
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends