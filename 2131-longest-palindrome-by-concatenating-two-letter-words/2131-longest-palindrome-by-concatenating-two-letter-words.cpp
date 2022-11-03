class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int l = words.size();
        unordered_map<string,int> mp;
        for(int i=0;i<l;i++){
            mp[words[i]]++;
        }
        
        unordered_map<string,int> :: iterator it;
        int ans = 0;
        int flag = 0;
        for(it=mp.begin();it!=mp.end();it++){
            string t = it->first;
            reverse(t.begin(),t.end());
            if(it->first.compare(t) == 0){
                if(mp[t]%2==1){
                    flag=2;
                }
                ans = ans + (4*(mp[t]/2));
            } else if(mp.find(t) != mp.end()){
                int mn = min(it->second,mp[t]);
                ans = ans + ( 4 * mn );
                mp[t]  = mp[t] - mn;
                mp[it->first] = it->second - mn; 
            }  
        }
        
        return ans+flag;
    }
};