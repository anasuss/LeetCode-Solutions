//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int a[], int b[], int n, int m, int k)
    {
      if (n>m) return kthElement(b,a,m,n,k) ; 
    int l = 0 , r = n ;
    while(l<=r){
           int cut1 = l+(r-l)/2 ;
           int cut2 = k-cut1 ;
           if (cut2>m){
                l = cut1+1 ;
                continue ;
           }
            if (cut2<0){
                r = cut1-1 ;
                continue ;
           }
           int l1 = cut1<=0 ? INT_MIN : a[cut1-1] ;
           int l2 = cut2<=0 ? INT_MIN : b[cut2-1] ;
           int r1 = cut1>=n ? INT_MAX : a[cut1] ;
           int r2 = cut2>=m ? INT_MAX : b[cut2] ;
           if (l1<=r2 && l2<=r1){
               return  max(l1,l2) ;
           }
           if (l1<r2)
                l = cut1+1 ;
            else
                r = cut1-1 ;
   }
       return 0 ; 
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends