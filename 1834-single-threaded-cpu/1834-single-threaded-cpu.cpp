class Solution {
    bool static compare (vector<int>& a, vector<int>& b) {
        if (a[0]==b[0]) {
            if (a[1]==b[1]) {
                return a[2]<a[2];
            } else {
                return a[1]<b[1];
            }
        } return a[0]<b[0];
        
    }
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> ans;
        // if (n==1) {
        //     ans.push_back(0);
        //     return ans;
        // }
        for (int i=0;i<n;i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end(),compare);
       //  for (int i=0;i<n;i++)
            // cout <<tasks[i][0]<<" "<<tasks[i][1]<<" "<<tasks[i][2]<<endl; 
                         
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        long long int t = tasks[0][0];
        int i = 0;
        
        while (i<n || pq.size()>0)  {
            while (i<n && tasks[i][0] <= t) {
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            if (pq.size()>0) { 
                t += pq.top().first;
                ans.push_back(pq.top().second);
                pq.pop();
            } else if (i<n) {
                t = tasks[i][0];
            }
        }
        
        return ans;
        
    }
};