class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int i=0;
        int n=nums.size();
        int a=0;
        for (int i=0;i<n;i++) {
            if (nums[a]<nums[i]) {
                a=i;
            }
        }
        int b;
        if ( a != 0){
            b = 0; 
        } else {
            b = 1;
        }
        
        for (int i=0;i<n;i++) {
            if ( i == a ) {
                continue;
            }
            if (nums[b]<nums[i]) {
                b = i;
            }
        }
        
        return (nums[a]-1)*(nums[b]-1);
       
    
    }
};