class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0]=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum%k) == mp.end()){
                mp[sum%k]=i+1;
            }else if(i+1-mp[sum%k] >1){
                return true;
            }
        }
        return false;
    }
};