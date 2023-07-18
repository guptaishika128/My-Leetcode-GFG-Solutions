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
      int sum = 0; // To store sum of the deepest nodes till now
      int deepest = 0; // To store sum of deepest nodes
    int deepestSum(TreeNode* root, int depth){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            if(depth==deepest){
                sum += root->val;
            }else if(depth>deepest){
                sum = root->val;
                deepest = depth;
            }
        }
        deepestSum(root->left,depth+1);
        deepestSum(root->right,depth+1);
        return sum;
    }
    int deepestLeavesSum(TreeNode* root) {
       return deepestSum(root,0);
        
    }
};