class Solution {
    int solve (vector<vector<int>> & adj, int u,int parent, int seats, long long & ans) {
        int p = 1;
        for (int i=0;i<adj[u].size();i++) {
            int v = adj[u][i];
            if (parent == v) continue;
            p += solve(adj,v,u,seats,ans);
        }
        if (u>0)
            ans += (p+seats-1)/seats;
        return p;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> adj(n+1);
        for (int i=0;i<n;i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans = 0;
        int a = solve(adj,0,-1,seats,ans);
        return ans;
    }
};