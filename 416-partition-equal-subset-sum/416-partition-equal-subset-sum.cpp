class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        if(sum%2 == 1){
            return false;
        }
        
        sum/=2;
        
        int t[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(j==0){
                    t[i][j]=true;
                }else if(i==0){
                    t[i][j]=false;
                }else{
                    if(nums[i-1]<=j){
                        t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];  
                    }else{
                        t[i][j] = t[i-1][j];
                    }
                }
            }
        }
        return t[n][sum];
        
    }
};