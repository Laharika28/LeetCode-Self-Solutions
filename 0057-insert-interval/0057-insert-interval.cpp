class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& nI) {
        int n = intervals.size();
        if (n==0 || nI[0] > intervals[n-1][1]) {
            intervals.push_back(nI);
            return intervals;
        }
        if (nI[1] < intervals[0][0]) {
            intervals.insert(intervals.begin(),nI);
            return intervals;
        }
        for (int i=0;i<n;i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            
            if (i<n-1 && nI[0]>e && nI[1]<intervals[i+1][0]) {
                intervals.insert(intervals.begin()+i+1,nI);
                return intervals;
            }
            
            if ((s>=nI[0] && e<=nI[1]) || (nI[0]>=s && nI[0]<=e) || (nI[1]>=s && nI[1]<=e)) {
                if (i==n-1 || nI[1]<intervals[i+1][0]) {
                    intervals[i][0] = min(s,nI[0]);
                    intervals[i][1] = max(e,nI[1]);
                } else {
                    int mn = min(nI[0],s);
                    int mx = max(e,nI[1]);
                    int j = i;
                    while (j<intervals.size() && nI[1]>intervals[j][1]) {
                        intervals.erase(intervals.begin()+j);
                    }
                    if (intervals.size()==j) {
                        intervals.push_back({mn,mx});
                    } else {
                        if (intervals[j][0]<=nI[1])
                            intervals[j][0] = mn;
                        else 
                            intervals.insert(intervals.begin()+j,{mn,mx});
                            
                    }                    
                }
                return intervals;
            }
        }
        return intervals;
    }
};