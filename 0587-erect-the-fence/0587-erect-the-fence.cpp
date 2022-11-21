class Solution {
public:
    
    bool find_cross_product ( vector<int> p, vector<int> q, vector<int> r ) {
        return ((q[0]-p[0])*(r[1]-q[1]) - (q[1]-p[1])*(r[0]-q[0])) >= 0 ;
    }
        
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(),trees.end());
        
        vector<vector<int>> ans;
        
        for (int i=0;i<trees.size();i++) {
            while ( ans.size()>1 && !find_cross_product(ans[ans.size()-2],ans[ans.size()-1],trees[i])) {
                ans.pop_back();
            }
            ans.push_back(trees[i]);
        }
        
        if (ans.size() == trees.size()) {
           return ans; 
        }
        
        for (int i=trees.size()-2;i>=0;i--) {
            while ( ans.size()>1 && !find_cross_product(ans[ans.size()-2],ans[ans.size()-1],trees[i])) {
                ans.pop_back();
            }
            ans.push_back(trees[i]);
        }
        ans.pop_back();
        return ans;
    }
};