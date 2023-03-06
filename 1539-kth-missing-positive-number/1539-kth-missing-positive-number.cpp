class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0,cnt=0,v=0;
        while (i<arr.size()) {
            v++;
            if (arr[i]==v) {
                i++;
            } else {
                cnt++;
                if (cnt == k) {
                    return v;
                }
            }    
        } 
        while (cnt<k) {
            v++;
            cnt++;
        }
        return v;
    }
};