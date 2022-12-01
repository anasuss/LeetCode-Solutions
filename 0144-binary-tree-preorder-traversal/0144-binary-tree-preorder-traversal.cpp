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
    vector<int> v ;
    void dfs(TreeNode* root){
        v.push_back(root->val) ; 
        if (root->left != nullptr)
            dfs(root->left) ; 
        if (root->right != nullptr)
            dfs(root->right) ; 
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {} ; 
        dfs(root);
        return v ; 
    }
};