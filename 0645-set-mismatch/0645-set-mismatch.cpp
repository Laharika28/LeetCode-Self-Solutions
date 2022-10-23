class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int s1 = 0;
        for(int i=0;i<n;i++){
            s1+=nums[i];
        }
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1] < 0){
                ans.push_back(abs(nums[i]));
                break;
            }else{
                nums[abs(nums[i])-1] = (-1)*nums[abs(nums[i])-1];   
            }
        }
        int s2 = (n*(n+1))/2;
        ans.push_back(s2-s1+ans[0]);
        return ans;
    }
};