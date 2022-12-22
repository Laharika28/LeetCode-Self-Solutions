class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int c = 0;
        for (int i=n-1;i>=0;i--) {
            digits[i]++;
            if (digits[i]<=9) {
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};