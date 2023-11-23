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
    TreeNode* helper(vector<int>& A ,  int& value, int bound){
        if(value == A.size() || A[value]>bound){
            return NULL;
        }
        TreeNode* root = new TreeNode(A[value++]);
        root->left = helper(A,value,root->val);
        root->right = helper(A,value,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder,i,INT_MAX);
        
    }
};