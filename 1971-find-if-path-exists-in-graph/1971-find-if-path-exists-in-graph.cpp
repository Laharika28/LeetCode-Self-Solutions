class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        vector<int> vis(n,false);
        
        q.push(source);
        
        while(q.size()>0) {
            int u = q.front();
            q.pop();
            vis[u] = true;
            if ( u == destination ) {
                return true;
            }
            for (int i=0;i<adj[u].size();i++) {
                int v = adj[u][i];
                if (!vis[v]) {
                    q.push(v);
                }
            }
        }
        
        return false;
        
    }
};