class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,-1));
        queue<vector<int>> q;
        // {x,y,steps,k}
        q.push({0,0,0,k});
        while(!q.empty()){
            vector<int> t = q.front();
            q.pop();
            int x = t[0];
            int y = t[1];
            int steps = t[2];
            int kLeft = t[3];
            
            if(x==n-1 && y==m-1){
                return steps;
            }
            
            if(x<0 || y<0 || x>=n || y>=m){
                continue;
            }
            
            if(grid[x][y]==1){
                if(kLeft>0){
                    kLeft--;
                }else{
                    continue;
                }
            }
            
            if(vis[x][y]!=-1 && vis[x][y]>=kLeft){
                continue;
            }
            vis[x][y]=kLeft;
            q.push({x-1,y,steps+1,kLeft});
            q.push({x,y-1,steps+1,kLeft});
            q.push({x+1,y,steps+1,kLeft});
            q.push({x,y+1,steps+1,kLeft});
        }
        return -1;
    }
};