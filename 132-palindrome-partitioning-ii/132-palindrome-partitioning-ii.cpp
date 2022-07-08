class Solution {
public:
    
    bool isPalindrome(string& s, int i, int j,vector<vector<int>>& dp1) {
		if (i >= j) return true;
		if (dp1[i][j] != -1) return dp1[i][j];
		if (s[i] == s[j]) return dp1[i][j] = isPalindrome(s, i + 1, j - 1,dp1);
		return dp1[i][j] = false;
	}
    
    int solve(string &s,int i,int j,vector<vector<int>>& dp,vector<vector<int>>& dp1){
        if(i>=j)return 0;
        if(isPalindrome(s,i,j,dp1))return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = INT_MAX;
        for(int k=i;k<=j-1;k++){
            if(isPalindrome(s,i,k,dp1)){
                int temp = 1+solve(s,k+1,j,dp,dp1);
                ans = min(ans,temp);
            }
        }
        return dp[i][j] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp1(n,vector<int>(n,-1));
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp,dp1);
    }
};