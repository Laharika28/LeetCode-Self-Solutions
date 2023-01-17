class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count_ones = 0;
        int count_flips = 0;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '0') {
                count_flips = min(count_ones,count_flips+1);
            } else {
                count_ones++;
            }
        }
        return count_flips;
    }
};