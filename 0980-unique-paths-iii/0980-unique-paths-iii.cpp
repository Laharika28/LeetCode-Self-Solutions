class Solution {
    
    bool isSafe (vector<vector<int>>& grid,vector<vector<bool>>& vis,int x,int y,int n,int m) {
        if (x<0 || y<0 || x>=n || y>=m || vis[x][y] || grid[x][y]==-1) {
            return false;
        }
        return true;
    }
    
    bool isValid (vector<vector<int>>& grid,vector<vector<bool>>& vis,int n,int m) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j]==0 && !vis[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    void solve (vector<vector<int>>& grid,vector<vector<bool>>& vis,int x,int y,int fx,int fy,int n,int m,int & ans) {
        if (x==fx && y==fy) {
            if (isValid(grid,vis,n,m)) {
                ans++;
            }
            return;
        }
        vis[x][y] = true;
        if (isSafe(grid,vis,x-1,y,n,m)) {
            solve(grid,vis,x-1,y,fx,fy,n,m,ans);
        } 
        if (isSafe(grid,vis,x+1,y,n,m)) {
            solve(grid,vis,x+1,y,fx,fy,n,m,ans);
        } 
        if (isSafe(grid,vis,x,y-1,n,m)) {
            solve(grid,vis,x,y-1,fx,fy,n,m,ans);
        }
        if (isSafe(grid,vis,x,y+1,n,m)) {
            solve(grid,vis,x,y+1,fx,fy,n,m,ans);
        }
        vis[x][y] = false;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ix,iy,fx,fy;
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j]==1) {
                    ix=i; iy=j;
                } else if (grid[i][j]==2) {
                    fx=i; fy=j;
                }
            }
        }
        
        solve(grid,vis,ix,iy,fx,fy,n,m,ans);
        return ans;
    }
};