class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        int steps = 0;
        int n = arr.size();
        if (n==1) return 0;
        queue<int> q;
        vector<bool> vis(n,false);
        for (int i=0;i<n;i++) {
            mp[arr[i]].push_back(i);
        }
        
        q.push(0);
        vis[0] = true;
        
        while (!q.empty()) {
            int m = q.size();
            for (int j=0;j<m;j++) {
                int a = q.front();
                q.pop();
                if (a == n-1) {
                    return steps;
                }
                vector<int> & v = mp[arr[a]];
                v.push_back(a-1);
                v.push_back(a+1);
                for (int i=0;i<v.size();i++) {
                    if (v[i]>=0 && v[i]<=n-1 && !vis[v[i]]) {
                        q.push(v[i]);
                        vis[v[i]] = true;
                    }
                }
                v.clear();
            }
            steps++;
        }
        return -1;
    }
};