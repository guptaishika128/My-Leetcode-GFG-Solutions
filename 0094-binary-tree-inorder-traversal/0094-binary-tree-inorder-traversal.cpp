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
    void Inorder(TreeNode* curr , vector<int>& inorder){
        if(curr == NULL){
            return;
        }
        
        Inorder(curr->left , inorder);
        inorder.push_back(curr->val);
        Inorder(curr->right , inorder);
    }
    
    
    
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        Inorder(root,inorder);
        return inorder;
    }
};