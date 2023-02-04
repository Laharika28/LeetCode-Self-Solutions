class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int l1 = s1.length();
        int l2 = s2.length();
        if (l2 < l1) return false;
        if (l1 == l2) {
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            return (s1==s2);
        }
        
        int x = 0;
        unordered_map<char,int> mp;
        for (int i=0;i<l1;i++) {
            mp[s1[i]]++;
        }
        bool flag = false;
        
        int l=0, r=0;
        int cnt = mp.size();
        while (r<l2) {
            if (mp.find(s2[r]) != mp.end()) {
                mp[s2[r]]--;
                if (mp[s2[r]] == 0) {
                    cnt--;
                }
            }
            
            if (r-l+1 == l1) {
                if (cnt == 0) return true;
                if (mp.find(s2[l]) != mp.end()) {
                    mp[s2[l]]++;
                    if (mp[s2[l]] == 1) {
                        cnt++;
                    }
                }
                l++;
            }
            r++;
        }
        
        return false;
    }
};