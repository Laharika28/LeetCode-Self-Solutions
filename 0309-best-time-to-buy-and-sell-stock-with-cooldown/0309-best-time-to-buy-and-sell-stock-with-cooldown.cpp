class Solution {
    int solve (int i,vector<int>& prices,bool isBuy, vector<vector<int>> & mp) {
        if (i>=prices.size()) {
            return 0;
        }
        if (mp[i][isBuy] != -1) {
            return mp[i][isBuy];
        }
        if (isBuy) {
            return mp[i][isBuy] = max(prices[i]+solve(i+2,prices,false,mp),solve(i+1,prices,true,mp));
        } else {
            return mp[i][isBuy] = max(-prices[i]+solve(i+1,prices,true,mp),solve(i+1,prices,false,mp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> mp(n, vector<int>(n,-1));
        return solve(0,prices,false,mp);
    }
};