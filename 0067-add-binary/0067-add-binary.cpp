class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i;
        int carry = 0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for (i=0;i<min(a.size(),b.size());i++) {
            if (a[i]=='0' && b[i]=='0') {
                ans.push_back('0'+carry);
                carry = 0;
            } else if (a[i]=='1' && b[i]=='1') {
                if (carry == 0) {
                    ans.push_back('0');
                } else {
                    ans.push_back('1');
                }
                carry = 1;
            } else {
                if (carry == 0) {
                    ans.push_back('1');
                } else {
                    ans.push_back('0');
                    carry = 1;
                }
            }
        }
        
        if (i==a.size()) {
            a=b;
        }
        
        for (;i<a.size();i++) {
            if (a[i] == '0') {
                ans.push_back('0'+carry);
                carry = 0;
            } else {
                if (carry == 1) {
                    ans.push_back('0');
                } else {
                    ans.push_back('1');
                }
            }
        }
        if (carry==1) {
            ans.push_back('1');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};