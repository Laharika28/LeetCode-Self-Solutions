class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        int n = tasks.size();
        
        for (int i=0;i<n;i++) {
            mp[tasks[i]]++;
        }
        
        unordered_map<int,int> :: iterator it;
        int cnt = 0;
        
        for (it=mp.begin();it!=mp.end();it++) {
            int a = it->second;
            if ( a == 1) {
                return -1;
            }
            if (a%3 == 0) {
                cnt += (a/3); 
            } else {
                cnt += (a/3)+1;
            }
        }
        
        return cnt;
    }
};