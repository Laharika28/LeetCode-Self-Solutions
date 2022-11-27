class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        if (n<3) {
            return 0;
        }
        int cnt = 0;
        vector<unordered_map<long, long>> t(n + 1);
        int ans = 0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<i;j++) {
                long d = (long long)(nums[i])-(long long)(nums[j]);
                t[i][d] = t[i][d] + t[j][d] + 1;
                ans = ans + t[j][d];
            }
        }
        return ans;
    }
};