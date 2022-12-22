class Solution {
    void dfs(vector<vector<int>> & adj, vector<int> &level,int i,int n,vector<bool> &vis,int l,vector<int>& child) {
        vis[i] = true;
        level[i] = l;
        for (int j=0;j<adj[i].size();j++) {
            int v = adj[i][j];
            if (vis[v]) {
                continue;
            }
            dfs(adj,level,v,n,vis,l+1,child);
            child[i] = child[i] + child[v];
        }
    }
    
    void dfs_2(vector<vector<int>>& adj,vector<bool>& vis,int i,vector<int>& ans,vector<int>& child ) {
        vis[i] = true;
        for (int j=0;j<adj[i].size();j++) {
            int v = adj[i][j];
            if (vis[v]) {
                continue;
            }
            ans[v] = ans[i] - child[v] + child[0]-child[v];
            dfs_2(adj,vis,v,ans,child);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n,false);
        vector<int> level(n,0);
        vector<int> child(n,1);
        dfs(adj,level,0,n,vis,0,child);
        vector<int> ans(n,0);
        for (int i=0;i<n;i++) {
            ans[0]  = ans[0] + level[i];
        }

        for (int i=0;i<n;i++) vis[i] = false;
        
        dfs_2(adj,vis,0,ans,child);
        
        return ans;
    }
};