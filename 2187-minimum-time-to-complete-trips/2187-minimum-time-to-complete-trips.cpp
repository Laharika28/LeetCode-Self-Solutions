class Solution {
    bool solve (vector<int> & time,long long day,int trips) {
        long long curr = 0;
        for (int i=0;i<time.size();i++) {
            curr += (day/time[i]);
            if (curr >= trips) {
                return true;
            }
        }
        return false;
    } 
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        if (n==1) {
            long long ans = (long long)totalTrips*(long long)time[0];
            return ans;
        }
        sort(time.begin(),time.end());
        long long l=0,r=9223372036854775807;
        while (l<r) {
            long long mid = (l+r)/2;
            if (solve(time,mid,totalTrips)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};