class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        int i = n-1;
        
        while (i>=0) {
            if (s.empty()) {
                ans[i] = 0;
            } else {
                while (s.size()>0 && temperatures[i] >= temperatures[s.top()] ) {
                    s.pop();
                }
                if (s.empty()) {
                    ans[i] = 0;
                } else {
                    ans[i] = s.top()-i;
                }
            }
            s.push(i);
            i--;
        }
        return ans;
    }
};