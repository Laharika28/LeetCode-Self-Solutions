class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> mp_s,mp_p;
        
        for (int i=0;i<p.length();i++) {
            mp_p[p[i]]++; 
        }
        
        int l = 0, r = 0;
        vector<int> ans;
        
        while (r<s.length()) {
            mp_s[s[r]]++;
            if (mp_s == mp_p) {
                ans.push_back(l);
                mp_s[s[l]]--;
                if(mp_s[s[l]] == 0) {
                    mp_s.erase(s[l]);
                }
                l++;
            }
            if(r-l+1 > p.length()) {
                mp_s[s[l]]--;
                if(mp_s[s[l]] == 0) {
                    mp_s.erase(s[l]);
                }
                l++;
                if (mp_s == mp_p) {
                ans.push_back(l);
                mp_s[s[l]]--;
                if(mp_s[s[l]] == 0) {
                    mp_s.erase(s[l]);
                }
                l++;
            }
            }
            r++;
        }
    
        return ans;
    }
};