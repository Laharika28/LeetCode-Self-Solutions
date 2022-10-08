class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum=nums[0]+nums[1]+nums[2];
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int s=nums[i]+nums[l]+nums[r];
                
                if(abs(s-target) < abs(sum-target)){
                    sum=s;
                } 
                
                if(s == target){
                    return sum;
                }else if(s < target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return sum;
    }
};