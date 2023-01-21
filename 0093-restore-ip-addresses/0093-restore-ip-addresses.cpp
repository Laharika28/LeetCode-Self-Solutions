class Solution {
    bool isValid(string s) {
        if (s.length()>3 || (s.length()>1 && s[0]=='0')) {
            return false;
        }
        int val = stoi(s);
        if (val>255) {
            return false;
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int l = s.length();
        if (l > 12) {
            return ans;
        }
        for (int i=1;i<=3;i++) {
            for (int j=1;j<=3;j++) {
                for (int k=1;k<=3;k++) {
                    if (l-i-j-k <= 3 && i+j+k<l) {
                        string a = s.substr(0,i);
                        string b = s.substr(i,j);
                        string c = s.substr(i+j,k);
                        string d = s.substr(i+j+k);
                        if (isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
                            ans.push_back(a+"."+b+"."+c+"."+d);
                        }
                    }
                }
            }
        }
        return ans;
    }
};