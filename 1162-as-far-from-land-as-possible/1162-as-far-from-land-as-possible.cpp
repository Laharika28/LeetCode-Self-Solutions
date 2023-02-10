class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                }
            }
        }
        
        if (q.size()==0 || q.size()==n*n) return -1;
        int cnt = -1;
        while (q.size()>0) {
            int s = q.size();
            cnt++;
            while (s>0) {
             int i = q.front().first;
             int j = q.front().second;
             q.pop();
             if (i-1>=0 && grid[i-1][j] == 0) {
                 grid[i-1][j] = 1;
                 q.push({i-1,j});
             } 
             if (i+1<n && grid[i+1][j] == 0) {
                 grid[i+1][j] = 1;
                 q.push({i+1,j});
             }
             if (j-1>=0 && grid[i][j-1] == 0) {
                 grid[i][j-1] = 1;
                 q.push({i,j-1});
             }
             if (j+1<n && grid[i][j+1] == 0) {
                 grid[i][j+1] = 1;
                 q.push({i,j+1});
             }
             s--;
            }
        }
        return cnt;
    }
};