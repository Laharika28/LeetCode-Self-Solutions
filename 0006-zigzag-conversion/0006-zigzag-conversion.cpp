class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int n = s.length();
        string t;
        vector<string> v(numRows);
        bool flag = false;
        int j=0;
        
        for (int i=0;i<n;i++) {
            if (j==0 || j==numRows-1) {
                flag = !flag;
            }
            v[j] += s[i];
            if (flag) {
                j++;
            } else {
                j--;
            }
        }
        for (int i=0;i<numRows;i++) {
            t += v[i];
        }
        return t;
    }
};