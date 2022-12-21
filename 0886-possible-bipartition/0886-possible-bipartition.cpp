class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1,-1);
        vector<vector<int>> adj(n+1);
        for(int i=0;i<dislikes.size();i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<pair<int,int>> q;
        for(int i=1;i<=n;i++) {
            if (color[i]!=-1) {
                continue;
            }
            q.push({i,0});
            color[i] = 0;
            while (q.size()>0) {
                int u = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int j=0;j<adj[u].size();j++) {
                    int v = adj[u][j];
                    if (color[v]==-1) {
                        color[v] = c^1;
                        q.push({v,c^1});
                    } else if (color[v] == c) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};