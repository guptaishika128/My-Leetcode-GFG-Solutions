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
    void preord(TreeNode* root , vector<int> &pre){
        // Pre -> ROOT , LEFT , RIGHT
        if(root==NULL){
            return;
        }
        
        pre.push_back(root->val);
        preord(root->left,pre);
        preord(root->right,pre);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        preord(root,pre);
        return pre;
    }
};