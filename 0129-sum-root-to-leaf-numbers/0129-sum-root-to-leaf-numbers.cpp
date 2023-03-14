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
    void solve (TreeNode* root,int & sum,int d) {
        d = (d*10) + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += d;
            return;
        }
        if (root->left != NULL)
            solve(root->left,sum,d);
        if (root->right != NULL)
            solve(root->right,sum,d);
    }
public:
    int sumNumbers(TreeNode* root) {
        if (root ==  NULL) {
            return 0;
        }
        int d = 0;
        int sum = 0;
        solve(root,sum,d);
        return sum;
    }
};