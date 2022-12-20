class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<bool> vis(n,false);
        vis[0] = true;
        for (int i=0;i<rooms[0].size();i++) {
            q.push(rooms[0][i]);
        }
        
        while (q.size()>0) {
            int r = q.front();
            q.pop();
            vis[r] = true;
            for (int i=0;i<rooms[r].size();i++) {
                if (!vis[rooms[r][i]]) {
                    q.push(rooms[r][i]);
                }
            }
        }
        
        for (int i=0;i<n;i++) {
            if (!vis[i]) {
                return false;
            }
        }
        return true;
        
    }
};