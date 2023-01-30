//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p){
        // Your code here
        unordered_map<char,int> mpp ; 
        unordered_map<char,int> mps ; 
        for (int i = 0 ; i<p.size() ; i++){
            ++mpp[p[i]] ; 
        }
        int cnt = 0 ; 
        int j = 0 ; 
        int start = -1 , length = s.size()+1 ; 
        for (int i = 0 ; i<s.size() ; i++){
            ++mps[s[i]] ; 
            if (mpp[s[i]]>=mps[s[i]])
                ++cnt ; 
            while(cnt == p.size()){
                if (length>i-j+1){
                    length = i-j+1 ; 
                    start = j ; 
                }
                mps[s[j]]-- ; 
                if (mpp[s[j]]>mps[s[j]]){
                    --cnt ;
                }
                ++j ; 
            }
        }
        if (start == -1)
            return "-1" ; 
        return s.substr(start,length) ;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends