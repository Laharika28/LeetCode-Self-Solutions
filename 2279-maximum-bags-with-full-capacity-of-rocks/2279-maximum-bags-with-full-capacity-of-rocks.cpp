class Solution {
    bool static compare (vector<int>& a,vector<int>& b) {
        return a[0]-a[1]<b[0]-b[1];
    }
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<vector<int>> bags(n,vector<int>(2));
        for (int i=0;i<n;i++) {
            bags[i][0]=capacity[i];
            bags[i][1]=rocks[i];
        }
        sort(bags.begin(),bags.end(),compare);
        
        int cnt = 0;
        for (int i=0;i<n;i++) {
            int diff = bags[i][0]-bags[i][1];
            if (additionalRocks >= diff) {
                additionalRocks -= diff;
                cnt++;
            } else {
                return cnt;
            }
        }
        return cnt;
    }
};