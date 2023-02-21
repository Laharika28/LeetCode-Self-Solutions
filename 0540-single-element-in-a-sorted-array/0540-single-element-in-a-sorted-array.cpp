class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        if (l==r) {
            return nums[l];
        }
        if (nums[0] != nums[1]) {
            return nums[0];
        } 
        if (nums[r] != nums[r-1]) {
            return nums[r];
        }
        int mid;
        while (l<=r) {
            mid = (l+r)/2;
            if (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) {
                return nums[mid];
            } else if (nums[mid] == nums[mid+1]) {
                if (mid%2==1) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            } else {
                if (mid%2==1) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};