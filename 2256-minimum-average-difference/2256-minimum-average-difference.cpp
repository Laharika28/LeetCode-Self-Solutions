class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int sum=0;
        int n=nums.size();
        
        for (int i=0;i<n;i++) {
            sum+=nums[i];
        }
        
        long long int csum=0;
        long long int ans=INT_MAX;
        int it=0;
        for (int i=0;i<n;i++) {
            csum+=nums[i];
            long long int a = (csum/(i+1));
            long long int b = (n-i-1)>0 ? ((sum-csum)/(n-i-1)) : 0;
            long long int curr = abs(a-b) ;
            if (curr < ans) {
                ans = curr;
                it=i;
            }
        }
        return it;
    }
};