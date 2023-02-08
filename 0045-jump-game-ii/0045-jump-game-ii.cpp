class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int last = 0;
        int end = 0;
        for (int i=0;i<n-1;i++) {
            last = max(last,i+nums[i]);
            if (last >= n-1) {
                return ++cnt;
            } 
            if (end == i) {
                ++cnt;
                end = last;
            }
        }
        return cnt;
    }
};