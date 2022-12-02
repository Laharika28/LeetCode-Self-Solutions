class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int l = word1.length();
        if (word2.length() != l) {
            return false;
        }
        unordered_map<char,int> mp1,mp2;
        for (int i = 0;i<l;i++) {
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
        
        unordered_map<int,int> mp;
        unordered_map<char,int> :: iterator it;
        
        for (it=mp1.begin();it!=mp1.end();it++) {
            if (mp2.find(it->first) == mp2.end()) {
                return false;
            }
            mp[it->second]++;
        }
        
        for (it=mp2.begin();it!=mp2.end();it++) {
            if (mp1.find(it->first) == mp1.end()) {
                return false;
            }
            mp[it->second]--;
        }
        
        unordered_map<int,int> :: iterator it1;
        
        for (it1=mp.begin();it1!=mp.end();it1++) {
            if (it1->second != 0) {
                return false;
            }
        }
        
        return true;
        
    }
};