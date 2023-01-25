//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int solve(string &s , int k ){
        int i = 0 , j = 0 , dist = 0; 
        int cnt[26] ; 
        memset(cnt,0,sizeof(cnt)) ; 
        long long int ans = 0 ;
        int n = s.size() ; 
        while(j<n){
            cnt[s[j]-'a']++ ;
            if (cnt[s[j]-'a'] == 1)
                dist++ ; 
            while(dist>k && i<n){
                cnt[s[i]-'a']-- ; 
                if (cnt[s[i]-'a'] == 0)
                    dist-- ; 
                ++i; 
            }
            ans+=j-i+1 ; 
            ++j ; 
        }
        return ans ; 
    }
    long long int substrCount (string &s, int k) {
    	//code here.
        return solve(s,k)-solve(s,k-1) ; 
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends