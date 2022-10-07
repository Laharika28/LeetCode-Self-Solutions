class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = ((m+n-1)/2)+1;
        for(int i=0;i<n;i++){
            nums1[i+m]=nums2[i];
        }
        while(gap>0){
            for(int i=0;i+gap<m+n;i++){
                if(nums1[i]>nums1[i+gap]){
                    int t=nums1[i];
                    nums1[i]=nums1[i+gap];
                    nums1[i+gap]=t;
                }
            }
            if(gap==1){
                break;
            }
            gap=((gap-1)/2)+1;
        }
    }
};