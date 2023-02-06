class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v(2*n);
        int it = 0;
        for (int i=0;i<n;i++) {
            v[it] = nums[i];
            v[it+1] = nums[i+n];
            it += 2;
        }
        return v;
    }
};