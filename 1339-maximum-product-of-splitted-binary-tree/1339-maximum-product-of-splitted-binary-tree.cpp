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
    
    long long int findSum (TreeNode* root) {
        if (!root) {
            return 0;
        }
        return root->val + findSum(root->left) + findSum(root->right);
    }
    long long int ans = 0;
    int solve (TreeNode* root,long long int sum) {
        if (!root) {
            return 0;
        }
        long long int temp = solve(root->left,sum) + solve(root->right,sum) + root->val;
        ans = max (ans,temp*(sum-temp));
        return temp;
    }
    
public:
    int maxProduct(TreeNode* root) {
        if (root==NULL) {
            return 0;
        }
        
        long long int sum = findSum(root);
        int mod = 1000000007;
        solve(root,sum);
        return ans%mod;
    }
};