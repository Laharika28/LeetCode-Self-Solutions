/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void solve (TreeNode* root, vector<int> & v) {
        if (root==NULL) {
            return;
        }
        v.push_back(root->val);
        solve(root->left,v);
        solve(root->right,v);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        solve(root,v);
        sort(v.begin(),v.end());
        int ans = INT_MAX;
        for (int i=0;i<v.size()-1;i++) {
            ans = min( ans , v[i+1]-v[i] );
        }
        return ans;
    }
};