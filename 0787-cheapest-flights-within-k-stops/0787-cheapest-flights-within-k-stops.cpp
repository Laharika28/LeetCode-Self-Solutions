class Solution {
    int ans;
    void solve (vector<vector<pair<int,int>>> & adj, int s, int d, int k, int curr) {
        if (s == d) {
            ans = min(ans,curr);
            return;
        }
        if (k<0) {
            return;
        }
        for (int i=0;i<adj[s].size();i++) {
            int u = adj[s][i].first;
            int val = adj[s][i].second;
            solve (adj,u,d,k-1,curr+val);
        }
    }
public:
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     ans = INT_MAX;
    //     vector<vector<pair<int,int>>> adj(n);
    //     for (int i=0;i<flights.size();i++) {
    //         int u = flights[i][0];
    //         int v = flights[i][1];
    //         int d = flights[i][2];
    //         adj[u].push_back({v,d});
    //     }
    //     solve (adj,src,dst,k,0);
    //     if (ans == INT_MAX) 
    //         ans = -1;
    //     return ans;
    // }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
        vector<vector<pair<int,int>>> adj(n);
        for (int i=0;i<flights.size();i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int d = flights[i][2];
            adj[u].push_back({v,d});
        }
        queue<vector<int>> pq;
        pq.push({0,0,src});
        vector<int> dis(n,INT_MAX);
        dis[src] = 0;
        while (pq.size()>0) {
            vector<int>temp = pq.front();
            int d = temp[0];
            int u = temp[2];
            int cnt = temp[1];
            pq.pop();
            if (cnt>k) {
                continue;
            }
            for (int i=0;i<adj[u].size();i++) {
                int v = adj[u][i].first;
                int val = adj[u][i].second;
                if (dis[v] > val+d && cnt<=k) {
                    dis[v] = val+d;
                    pq.push({val+d,cnt+1,v});
                }
            }
        }
        if (dis[dst]==INT_MAX) {
            dis[dst] = -1;
        }
        return dis[dst];
    }
};