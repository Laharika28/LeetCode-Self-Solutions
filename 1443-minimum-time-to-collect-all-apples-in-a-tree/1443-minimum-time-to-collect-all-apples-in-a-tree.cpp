class Solution {
    int solve (vector<vector<int>>& adj,vector<bool>& hasApple,int node,int parent) {
        int dis = 0;
        for (int i=0;i<adj[node].size();i++) {
            int v = adj[node][i];
            if (v == parent) {
                continue;
            }
            int a = solve(adj,hasApple,v,node);
            if (hasApple[v]) {
                dis += (2+a);
                hasApple[node]=true;
            }
        }
        return dis;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return solve(adj,hasApple,0,0);
    }
};