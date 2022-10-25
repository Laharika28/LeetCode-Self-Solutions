class Solution {
public:
    
    int solve(int n, vector<int> & t){
        if(t[n] != -1){
            return t[n];
        }
        if(n<=2){
            return t[n]=n;
        }
        
        return t[n] = solve(n-1,t) + solve(n-2,t);
    }
    
    int climbStairs(int n) {
        
        if(n<=2){
            return n;
        }
        
        vector<int> t(n+1,-1);
        return solve(n,t);
    }
};