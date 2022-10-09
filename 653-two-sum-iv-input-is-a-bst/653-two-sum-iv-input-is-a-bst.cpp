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
    
    void solve(TreeNode* root,vector<int>& s,int k){
        if(root==NULL){
            return;
        }
        solve(root->left,s,k);
        s.push_back(root->val);
        solve(root->right,s,k);
    }
    
public:
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        solve(root,v,k);
        int l=0,r=v.size()-1;
        while(l<r){
            if(v[l]+v[r] == k){
                return true;
            }else if(v[l]+v[r] < k){
                l++;
            }else{
                r--;
            }
        }
        return false;
    }
};