class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        
        while ( i<n ) {
            if ( nums[i]<=0 ||  i == nums[i]-1 || nums[i]>n || nums[nums[i]-1] == nums[i]) {
                i++;
            } else {
                int t = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = t;
            }
        }
        
        for (int i=0;i<n;i++) {
            if (nums[i]<=0 || nums[i]-1 != i ) {
                return i+1;
            }
        }
        return n+1;
    }
};