class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
//         map<int,int> mp;
//         for(int i=0;i<nums.size();i++)
//         {
//             mp[nums[i]] ++;
//         }
       
//         map<int,int> ::  iterator ip;
//         vector<int> v;
//         for(ip=mp.begin();ip!=mp.end();ip++)
//         {
//             v.push_back(ip->first);
//         n
       
        sort(nums.begin(),nums.end());
        int si=nums.size();
       
     return (nums[si-1]*nums[si-2])-(nums[0]*nums[1]); 
    }
};