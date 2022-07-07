// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

int t[101][101];

class Solution{
public:

    
    int solve(int arr[],int i,int j){
        if(i>=j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        
        int ans=INT_MAX;
        
        for(int k=i;k<=j-1;k++){
            int temp1 = (t[i][k] == -1)?solve(arr,i,k):t[i][k];
            t[i][k]=temp1;
            
            int temp2= (t[k+1][j] == -1)?solve(arr,k+1,j):t[k+1][j];
            t[k+1][j]=temp2;
            
            ans=min(temp1+temp2+(arr[i-1]*arr[k]*arr[j]),ans);
        }
        return t[i][j]=ans;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        if(N<=2){
            return 0;
        }
        
        memset(t,-1,sizeof(t));
        
        return solve(arr,1,N-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends