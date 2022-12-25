class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        sort(nums.begin(),nums.end());
        int m = queries.size();
        vector<int> ans (m);
        int n = nums.size();
        vector<int> prefixSum (n,0);
        prefixSum[0] = nums[0];
        
        for (int i=1;i<n;i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        
        for (int i=0;i<m;i++) {
            ans[i] = upper_bound(prefixSum.begin(),prefixSum.end() ,queries[i]) - prefixSum.begin();
        }
        return ans;
    }
};