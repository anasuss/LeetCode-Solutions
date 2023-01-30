//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int n)
    {
        // code here
        vector<int> ans ; 
        while (n-2000>=0){
            n-=2000 ; 
            ans.push_back(2000) ;  
        }
        while (n-500>=0){
            n-=500 ;
            ans.push_back(500) ;  
        }
        while (n-200>=0){
            n-=200 ;
            ans.push_back(200) ; 
        }
        while (n-100>=0){
            n-=100 ;         
            ans.push_back(100) ; 
        }
        while (n-50>=0){
            n-=50 ;         
            ans.push_back(50) ; 
        }
        while (n-20>=0){
            n-=20 ;         
            ans.push_back(20) ; 
        }
        while (n-10>=0){
            n-=10 ;     
            ans.push_back(10) ; 
        }
        while (n-5>=0){
            n-=5 ;         
            ans.push_back(5) ; 
        }
        while (n-2>=0){
            n-=2 ;         
            ans.push_back(2) ; 
        }
        while (n-1>=0){
            n-=1 ;
            ans.push_back(1) ; 
        }
        return ans ; 
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends