class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> mx;
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > mn;
        int n = profits.size();
        
        for (int i=0;i<n;i++) {
            mn.push({capital[i],profits[i]});
        }
        
        while (k--) {
            while (mn.size()>0 && mn.top().first <= w) {
                mx.push(mn.top().second);
                mn.pop();
            }
            if (mx.size() == 0){
                break;
            }
            w += mx.top();
            mx.pop();
        }
        return w;
        
    }
};