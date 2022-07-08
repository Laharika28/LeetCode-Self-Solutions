// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

unordered_map<string,int> mp;
int mod=1003;
class Solution{
public:

    int solve(string s,int i,int j,int isTrue){
        if(i>j){
            return 0;
        }
        
        if(i==j){
            if(isTrue){
                return s[i]=='T';
            }
            else{
                return s[i]=='F';
            }
        }
        
        string key =to_string(i);
        key.push_back(' ');
        key.append(to_string(j));
        key.push_back(' ');
        key.append(to_string(isTrue));
        
        
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        
        int ans=0;
        
        for(int k=i+1;k<=j-1;k+=2){
            
            int lt=solve(s,i,k-1,true);
            int lf=solve(s,i,k-1,false);
            int rt=solve(s,k+1,j,true);
            int rf=solve(s,k+1,j,false);
            
            if(s[k]=='&'){
                if(isTrue){
                    ans=(ans+((lt*rt)%mod))%mod;
                }else{
                    ans=(ans+((lf*rf)+(lt*rf)+(lf*rt))%mod)%mod;
                }
            }else if(s[k]=='|'){
                if(isTrue){
                    ans=(ans+((lt*rt)+(lt*rf)+(lf*rt))%mod)%mod;
                }else{
                    ans=(ans+((lf*rf)%mod))%mod;
                }
            }else if(s[k]=='^'){
                if(isTrue){
                    ans=(ans+((lt*rf)+(lf*rt))%mod)%mod;
                }else{
                    ans=(ans+((lt*rt)+(lf*rf))%mod)%mod;
                }
            }
        }
        
        return mp[key]=ans;
        
    }
    
    int countWays(int N, string S){
        // code here
        mp.clear();
        return solve(S,0,N-1,true);
        
    }
};

// { Driver Code Starts.

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
}  // } Driver Code Ends