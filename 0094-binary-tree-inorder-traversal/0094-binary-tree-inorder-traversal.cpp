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
    /*void inOrder(TreeNode* root){
        if (root == nullptr)
            return ; 
        inOrder(root->left) ; 
        v.push_back(root->val) ; 
        inOrder(root->right) ; 
    }*/
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s ;
        TreeNode* node = root ; 
        while(1){
            if (node != nullptr){
                s.push(node) ; 
                node = node->left ; 
            }else{
                if (s.empty())
                    break ; 
                node = s.top() ; 
                s.pop() ; 
                v.push_back(node->val) ; 
                node = node -> right ; 
            }
        }
        return v ; 
    }
};