class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        if (nums.size() == 2) {
           if (nums[0]==nums[1]) {
               return 1;
           } 
           return 2;
        }
        
        
        
        int l=1,r=1,n=nums.size();
        if(nums[0] == nums[n-1]) {
            return 1;
        }
        unordered_set<int> s;
        s.insert(nums[0]);
        while ( l<n && r<n) {
            if(s.find(nums[l]) != s.end()) {
                while ( r<n && s.find(nums[r]) != s.end()) {
                    r++;
                }
                if(r>=n) {
                    break;
                }
                nums[l] = nums[r];
                r++;
            }
            s.insert(nums[l]);
            l++;
        }
        return l;
    }
};