//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    int solve (int arr[], int l,int r) {
        if (l>=r) {
           return 0; 
        }
        
        if (l==r-1) {
            if (arr[l]>arr[r]) {
                return r;
            } else {
                return 0;
            }
        }
        
        
        int mid = (l+r) / 2;
        
        if (arr[l]>arr[mid]) {
            return solve(arr,l,mid);
        }
        
        
        return solve(arr,mid,r);
    }
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    return solve(arr,0,n-1);
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends