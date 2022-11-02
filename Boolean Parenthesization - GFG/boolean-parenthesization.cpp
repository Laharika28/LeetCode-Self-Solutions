//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[201][201][2];
    int mod=1003;

   int solve(string s,int i,int j,int isTrue)
   {
       
       if(i>j)
       {
           return 0;
       }
       if(t[i][j][isTrue] != -1 )
       {
           return t[i][j][isTrue];
       }
       
       if(i==j)
       {
           if(isTrue == 1)
           {
                return s[i] == 'T';
           }
           else
           {
               return s[i] == 'F';
           }
       }
       int ans=0;
       
       for(int k=i+1;k<=j-1;k+=2)
       {
           
           int lt=solve(s,i,k-1,1);
           int lf=solve(s,i,k-1,0);
           int rt=solve(s,k+1,j,1);
           int rf=solve(s,k+1,j,0);
           
           
           if(s[k] == '&')
           {
               if(isTrue == 1)
               {
                       ans=(ans + ((lt * rt)%mod)%mod);
               }
               else
               {
                   ans=(ans + ((lf*rt)%mod) + ((lt*rf)%mod) + ((lf * rf)%mod));
               }
           }
           else if(s[k] == '|')
           {
               if(isTrue == 1)
               {
                   ans=ans+((lt*rt)%mod) + ((lt*rf)%mod) + ((lf*rt)%mod);
               }
               else
               {
                   ans=ans+((lf*rf)%mod);
               }
           }
          else if(s[k] == '^')
          {
              if(isTrue == 1)
              {
                  ans=ans+((lf*rt)%mod) + ((lt*rf)%mod);
              }
              else
              {
                  ans=ans+((lt*rt)%mod) + ((lf*rf)%mod);
              }
               
           }
         
          
       }
       return t[i][j][isTrue]=ans%mod;
       
   }

    int countWays(int N, string S){
        // code here
        
        int ans;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<2;k++){
                    t[i][j][k]=-1;
                }
            }
        }
        ans=solve(S,0,N-1,1);
        
  
        return ans;
        
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends