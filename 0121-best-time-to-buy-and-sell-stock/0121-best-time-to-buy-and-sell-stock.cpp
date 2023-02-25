class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> mn (n);
        mn[0] = prices[0];
        vector<int> mx (n);
        mx[n-1] = prices[n-1];
        for(int i=1;i<n;i++) {
            mn[i] = min( mn[i-1] , prices[i] );
            mx[n-i-1] = max( mx[n-i] , prices[n-i-1] );
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max( ans, mx[i]-mn[i] );
        }

        return ans;
    }
};