class Solution {
    int kadanes1(vector<int>& nums) {
        int c_sum=0;
        int sum = nums[0];
        for (int i=0;i<nums.size();i++) {
            c_sum += nums[i];
            if (c_sum<0) {
                c_sum = 0; 
            } else {
                sum = max(sum,c_sum);
            }
            sum = min(sum,nums[i]);
        }
        return sum;
    }
    int kadanes2(vector<int>& nums) {
        int c_sum=0;
        int sum = nums[0];
        for (int i=0;i<nums.size();i++) {
            c_sum += nums[i];
            if (c_sum<0) {
                c_sum = 0; 
            } else {
                sum = max(sum,c_sum);
            }
        }
        return sum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int m_sum = nums[0];
        int n = nums.size();
        int sum = 0;
        bool isPos = false;
        int m = nums[0];
        for (int i=0;i<n;i++) {
            sum += nums[i];
            if (nums[i] > 0) {
                isPos = true;
            } else {
                m = max(nums[i],m);
            }
        }
        if (!isPos) {
            return m;
        }
        int s1 = kadanes2(nums);
        for (int i=0;i<n;i++) {
            nums[i] = (-1)*nums[i];
        }
        int s2 = kadanes2(nums);
        
        return max(s1,sum+s2);
    }
};