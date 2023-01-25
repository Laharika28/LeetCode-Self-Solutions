class Solution {
    void find_dis(int n, vector<int> & dis, vector<int> & edges, vector<bool> & vis) {
        vis[n] = true;
        int n1 = edges[n];
        if (n1 != -1 && !vis[n1]) {
            dis[n1] = dis[n] + 1;
            find_dis(n1,dis,edges,vis);
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<bool> vis1(n,false);
        vector<bool> vis2(n,false);
        vector<int> dis1(n,0), dis2(n,0);
        find_dis(node1,dis1,edges,vis1);
        find_dis(node2,dis2,edges,vis2);
        int ans = -1;
        int dis = INT_MAX;
        for (int i=0;i<n;i++) {
            // cout<<vis1[1]<<" "<<vis2[i]<<endl;
            if (vis1[i] && vis2[i]) {
                int d = max(dis1[i],dis2[i]);
                if (dis > d) {
                    dis = d;
                    ans = i;
                }
            }
        }
        return ans;
        
    }
};