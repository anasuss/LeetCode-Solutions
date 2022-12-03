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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {} ; 
        queue<TreeNode*> q ;
        vector<vector<int>> ans ;
        vector<int> v ; 
        q.push(root) ; 
        for (int sz = q.size() ; !q.empty() ; sz = q.size()){
            v.clear() ; 
            while(sz--){
                TreeNode* f = q.front() ; 
                v.push_back(f->val) ; 
                q.pop() ; 
                if (f->left != nullptr)
                    q.push(f->left) ; 
                if (f->right != nullptr)
                    q.push(f->right) ; 
            }
            ans.push_back(v) ; 
        }
        return ans ; 
    }
};