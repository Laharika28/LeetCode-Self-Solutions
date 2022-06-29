// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        // code here 
        int x=0,y=n-1;
        int i=0;
        while(i<=y ){
            if(arr[i] == 0){
                int t=arr[x];
                arr[x]=arr[i];
                arr[i]=t;
                x++;
                i++;
            }
            else if(arr[i] == 2){
                int t=arr[y];
                arr[y]=arr[i];
                arr[i]=t;
                y--;
            }
            else{
                i++;
            }
        }
    }

};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends