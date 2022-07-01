// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int m, int n) {

        // code here.
        long long t[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(j==0){
                    t[i][j]=1;
                }else if(i==0){
                    t[i][j]=0;
                }else{
                    if(S[i-1]<=j){
                        t[i][j]=t[i][j-S[i-1]]+t[i-1][j];
                    }else{
                        t[i][j]=t[i-1][j];
                    }
                }
            }
        }
        return t[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends