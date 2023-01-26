//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string &s){
        int i = 0 , j = 0 ; 
        int n = s.size() ; 
        int mp[26] ; 
        memset(mp,0,sizeof(mp)) ; 
        int ans = 0 ; 
        while(i<n){
            mp[s[i]-'a']++ ;  
            while(mp[s[i]-'a']>1 && j<=i){
                mp[s[j]-'a']-- ; 
                ++j ; 
            }
            ans = max(ans,i-j+1) ;
            ++i ; 
        }
        return ans ;    
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends