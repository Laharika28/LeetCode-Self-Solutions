class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> mp;
        int c = 0;
        mp[' '] = ' ';
        
        for (int i=0;i<key.size();i++) {
            if (mp.find(key[i]) == mp.end()) {
                mp[key[i]] = c + 'a';
                c++;
            }
        }
       
        string ans ;
        
        for (int i=0;i<message.size();i++) {
            ans.push_back(mp[message[i]]);
        }
        return ans;
    }
};