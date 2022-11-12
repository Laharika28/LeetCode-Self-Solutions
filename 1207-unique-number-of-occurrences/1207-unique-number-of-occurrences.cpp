class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]] ++;
        }
       
        bool flag=true;
       
        unordered_map<int,int> :: iterator ip;
        vector<int> v;
        for(ip=mp.begin() ; ip!=mp.end() ; ip++)
        {
            v.push_back(ip->second);
        }
       
        sort(v.begin() , v.end());
        for(int i=0;i<v.size()-1 ; i++)
        {
            if(v[i] == v[i+1])
            {
                flag=false;
            }
        }
        return flag;
       
    
    }
};