//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>> v ; 
        for (int i = 0 ; i<n ; i++){
            int x = arr[i].value ; 
            int y = arr[i].weight ; 
            double k = (double)x/(double)y ;
            v.push_back({k,i}) ; 
        }
        sort(v.rbegin(),v.rend()) ; 
        double ans = 0 ; 
        for (int i = 0 ; i<n ; i++){
            int idx = v[i].second ; 
            if (W-arr[idx].weight>=0){
                W-=arr[idx].weight ; 
                ans+=arr[idx].value ; 
            }else{
                ans+=(v[i].first*W) ; 
                break ; 
            }
        }
        return ans ; 
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends