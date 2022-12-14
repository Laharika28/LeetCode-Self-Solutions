class Solution {
    int solve (vector<int>& arr,int i,int n,vector<int>& t) {
        if (i>=n) {
            return 0;
        }
        if (t[i]!=-1) {
            return t[i];
        }
        return t[i] = max (solve(arr,i+1,n,t),arr[i]+solve(arr,i+2,n,t));  
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n+1,-1);
        return solve(nums,0,n,t);
    }
};