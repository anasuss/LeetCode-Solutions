//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmpr(pair<int,int> x , pair<int,int> y){
        if (x.first != y.first)
            return x.first>y.first; 
        return x.second<=y.second ; 
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>> v ;
        int ans = 0 ; 
        int nb = 0 ; 
        int mx = 0 ; 
        for (int i = 0 ; i<n ; i++){
            mx = max(arr[i].dead,mx) ; 
            v.push_back({arr[i].profit,arr[i].dead}) ;
        }
        int a[mx+10] ; 
        memset(a,-1,sizeof(a)) ; 
        sort(v.begin(),v.end(),cmpr) ;

        for (int i = 0 ; i<v.size() ; i++){
            int idx = v[i].second ; 
            while(idx>1 && a[idx] != -1)
                --idx;
            if (a[idx] == -1){
                a[idx] = v[i].first ; 
                ans+=a[idx] ; 
                ++nb ; 
            }
        }
        return {nb,ans};  
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends