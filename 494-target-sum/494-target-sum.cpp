class Solution {
    
public:
    int subsetcount(vector<int> arr, int size, int s)
{

    int t[size + 1][s + 1];
    for (int i = 0; i < (size + 1); i++)

    {
        for (int j = 0; j < (s + 1); j++)
        {

            if (i == 0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < (size + 1); i++)
    {
        for (int j = 0; j < (s + 1); j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]]) + (t[i - 1][j]);
            }
            if (arr[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[size][s];
}
   
   
   
   
    int findTargetSumWays(vector<int>& nums, int target) {
       
       
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
        }
        int s1;
        if(abs(target)>sum || ((target+sum) % 2 != 0)){
            return 0;
        }
        s1=(sum-target)/2;
       
        int ans;
        ans=subsetcount(nums,(nums.size()),s1);
        return ans;
       
    }

};