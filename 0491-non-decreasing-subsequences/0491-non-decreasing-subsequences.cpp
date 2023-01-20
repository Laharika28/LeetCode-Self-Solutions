class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        long long int l = pow(2,n);
        for (long long int i=0;i<l;i++) {
            vector<int> temp;
            for (int j=0;j<n;j++) {
                if (i & (1<<j)) {
                    temp.push_back(nums[j]);
                }
            }   
            if (temp.size()<2) {
                continue;
            }
            bool flag = true;
            for (int j=1;j<temp.size();j++) {
                if (temp[j-1]>temp[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (s.find(temp) == s.end()) {
                    ans.push_back(temp);
                    s.insert(temp);
                }
            }
        }
        return ans;
    }
};