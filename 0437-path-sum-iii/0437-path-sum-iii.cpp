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
    long long int solve(TreeNode* root,long long int targetSum) {
        if (!root) {
            return 0;
        }
        
        long long int a = 0;
        targetSum = targetSum - root->val;
        
        if (targetSum == 0) {
            a++;
        }
        
        return a + solve(root->left,targetSum) + solve(root->right,targetSum);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0;
        }
        
        int a = solve(root,targetSum);
        int lcnt = pathSum(root->left,targetSum);
        int rcnt = pathSum(root->right,targetSum);
        
        // if (targetSum-root->val == 0) {
        //     return 1+lcnt+rcnt;
        // }
        
        return a+lcnt+rcnt;
        
    }
};
























