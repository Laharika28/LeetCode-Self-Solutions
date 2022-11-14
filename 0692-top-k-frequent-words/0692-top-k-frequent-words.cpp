class Solution {
    
    static bool compare(pair<string,int>& a,pair<string,int>& b) {        
        return (a.second == b.second ? a.first < b.first : a.second > b.second);
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        vector<pair<string,int>> temp;
        priority_queue<pair<int,string>,vector<pair<int,string>>, greater<pair<int,string>>> pq;
        unordered_map<string,int> mp; 
        
        for (int i=0;i<words.size();i++) {
            mp[words[i]]++;
        }
        
        unordered_map<string,int> :: iterator it;
        for (it = mp.begin();it!=mp.end();it++) {
            temp.push_back({it->first,it->second});
        }
        
        sort(temp.begin(),temp.end(),compare);
        
        for(int i=0;i<k;i++) {
            ans.push_back(temp[i].first);
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};