class Solution {
    int solve (vector<vector<int>> & adj,string & s, int & ans, int u) {
        if (adj[u].size()==0) return 1;
        int m1=0, m2=0;
        for (int i=0;i<adj[u].size();i++) {
            int v = adj[u][i];
            int val = solve(adj,s,ans,v);
            ans = max(ans,val);
            if (s[u] == s[v]) {
                continue;
            }
            if (val>m1) {
                m2 = m1;
                m1 = val;
            } else if (val>m2) {
                m2 = val;
            }
        }
        ans = max(ans,1+m1+m2);
        return 1+m1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i=1;i<n;i++) {
            adj[parent[i]].push_back(i);
        }
        int ans = 1;
        solve(adj,s,ans,0);
        return ans;
    }
};