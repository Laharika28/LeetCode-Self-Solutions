class Solution {
    int countSubsetSum(vector<int>& arr,int n,int sum){
        int mod = 1000000007;
        long long t[n+1][sum+1];
        for(int j=0;j<sum+1;j++){
            t[0][j]=0;
        }
        t[0][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                
                    if(arr[i-1] <= j){
                        t[i][j] = ((t[i-1][j-arr[i-1]])%mod+(t[i-1][j])%mod)%mod;
                    }else{
                        t[i][j] = t[i-1][j]%mod;
                    }
            }
        }
        return t[n][sum];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(((sum+target)%2 == 1) || (abs(target)>sum))
            return 0;
        int s = (sum+target)/2;
        return countSubsetSum(nums,n,s);
    }
};