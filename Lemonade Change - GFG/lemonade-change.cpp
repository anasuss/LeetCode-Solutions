//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n , vector<int> &bills) {
        // code here
        int cnt5 = 0 , cnt10 = 0 ; 
        for (int i = 0 ; i<n ; i++){
            if (bills[i] == 5){
                cnt5++ ; 
            }else if (bills[i] == 10){
                cnt10++ ; 
                if (cnt5 <= 0){
                    return false ; 
                }else 
                    cnt5-- ; 
            }else if (bills[i] == 20){
                if (cnt5<=0)
                    return false ; 
                if (cnt10>=1 && cnt5>=1){
                    cnt10-=1 ; 
                    cnt5-=1 ; 
                }else if (cnt5>=3){
                    cnt5-=3 ; 
                }else
                    return false ; 
            }
        }
        return true ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends