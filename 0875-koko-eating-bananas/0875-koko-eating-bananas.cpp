class Solution {
    bool solve (vector<int>& piles,int h,int k) {
        int curr = 0;
        for (int i=0;i<piles.size();i++) {
            if (piles[i]%k == 0) {
                curr += (piles[i]/k);
            } else {
                curr = curr + (piles[i]/k) + 1;
            } 
            if (curr > h) {
                return false;
            }
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() == 1) {
            return (piles[0]%h==0?piles[0]/h:(piles[0]/h)+1);
        }
        long long int r = 0;
        long long int l = 1;
        
        for (int i=0;i<piles.size();i++) {
            r += piles[i];
        }
        
        while (l<r) {
            long long int mid = (l+r)/2;
            if (solve(piles,h,mid)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        
        return l;
                
    }
};