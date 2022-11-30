class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]] ++;
        }
       
        unordered_set<int> s;
        
        unordered_map<int,int> :: iterator it;
        
        for (it=mp.begin();it!=mp.end();it++) {
            if (s.find(it->second) != s.end()) {
                return false;
            }
            s.insert(it->second);
        }
        
        return true;
    }
};