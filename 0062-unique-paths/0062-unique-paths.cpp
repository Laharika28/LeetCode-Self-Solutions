class Solution {
public:

    int solve(int i,int j,int m,int n,vector<vector<int>> &t) {
        if(t[i][j]!=-1){
            return t[i][j];
        }

        if(i==m-1 && j==n-1) {
            return t[i][j]=1;
        }

        if(i>=m || j>=n) {
            return t[i][j]=0;
        }

        return t[i][j] = solve(i+1,j,m,n,t) + solve(i,j+1,m,n,t);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,t);
    }
};