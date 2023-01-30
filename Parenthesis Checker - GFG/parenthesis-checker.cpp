//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x){
        // Your code here
        stack<char> stk ; 
        for (int i = 0 ; i<x.size() ; i++){
            if (x[i] == '(' || x[i] == '{' || x[i] == '['){
                stk.push(x[i]) ; 
            }else{
                if (stk.empty())
                    return false ; 
                char c = stk.top() ; 
                stk.pop() ; 
                if (x[i] == ')' && c != '(')
                    return false ; 
                if (x[i] == ']' && c != '[')
                    return false ; 
                if (x[i] == '}' && c != '{')
                    return false ; 
            }
        }
        if (stk.empty())
            return true ;
        return false ; 
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends