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
    int maxDepth(TreeNode* root) {
        int height = 0;
        if(root==NULL){
            return 0;
        } else{
            int lheight = maxDepth(root->left);
            int rheight = maxDepth(root->right);
            
            if(lheight>rheight){
                height =  lheight+1;
            } else{
                height =  rheight+1;
            }
        }
        return height;
    }
};