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
public:
    
    int solve(TreeNode* root,int & res){
        if(root==NULL){
            return 0;
        }
        
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        int temp = max(root->val,root->val+max(l,r));
        res = max(res,max(temp,root->val+l+r));
        
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int res=INT_MIN;
        solve(root,res);
        return res;
    }
};