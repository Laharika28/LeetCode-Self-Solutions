class Solution {

    bool isPali(string s) {
        int r = s.length()-1;
        int l = 0;
        while(l<=r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    void solve (string s, vector<string> temp, vector<vector<string>> & ans) {
        if (s.length()==0) {
            ans.push_back(temp);
        }
        for (int i=0;i<s.length();i++) {
            string t = s.substr(0,i+1);
            if (isPali(t)) {
                string rem = s.substr(i+1,s.length()-i-1);
                temp.push_back(t);
                int n = temp.size();
                solve (rem,temp,ans);
                temp.erase(temp.begin()+n-1);
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int l = s.length();
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,temp,ans);
        return ans;
    }
};