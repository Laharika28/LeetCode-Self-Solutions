class Solution {

public:

    int firstUniqChar(string s) {
        unordered_map<char,int> mp;

        for(int i=0;i<s.size();i++)
        {
            mp[s[i]] ++;
        }

        // unordered_map<char,int> :: iterator ip;
        // char num='*';
        // for(ip=mp.begin() ; ip!=mp.end() ; ip++)
        // {
        //     if(ip->second == 1)
        //     {
        //       num = ip->first;  
        //     }
        // }

        for(int i=0;i<s.size();i++)
        {
            if(mp[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }

};
   

    
