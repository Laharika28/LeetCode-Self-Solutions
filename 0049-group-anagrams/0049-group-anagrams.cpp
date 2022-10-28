class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int l=0;
        string t;
        int n=strs.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            t=strs[i];
            sort(t.begin(),t.end());
            if(mp.find(t) != mp.end()){
                ans[mp[t]].push_back(strs[i]);
            }else{
                mp[t]=l++;
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};