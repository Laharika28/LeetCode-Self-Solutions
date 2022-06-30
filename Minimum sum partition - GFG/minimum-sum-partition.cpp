// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int subsetSum(int arr[] , int n,int sum){
        int t[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(j==0){
                    t[i][j]=true;
                }else if(i==0){
                    t[i][j]=false;
                }else{
                    if(arr[i-1] <= j){
                        t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                    }else{
                        t[i][j] = t[i-1][j];
                    }
                }
            }
        }
        
        int mn=INT_MAX;
        for(int j=0;j<=sum/2;j++){
            if(t[n][j]){
                mn = min(mn,sum-(2*j));
            }
        }
        return mn;
    }

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i =0;i<n;i++){
	        sum+=arr[i];
	    }
	    return subsetSum(arr,n,sum);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends