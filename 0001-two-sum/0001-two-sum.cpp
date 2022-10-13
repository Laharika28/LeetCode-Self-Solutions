class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int t;
        vector<pair<int,int>> temp;
        
        for(int i=0;i<nums.size();i++)
        {
            temp.push_back(make_pair(nums[i],i));
        }
        
        sort(temp.begin(),temp.end());
        
        vector<int> ans;
        while(l<r)
        {
            t=temp[l].first+temp[r].first;
            if(t==target)
            {
                ans.push_back(temp[l].second);
                ans.push_back(temp[r].second);
                return ans;
            }
            if(t<target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        ans.push_back(-1);
        return ans;
    }
};