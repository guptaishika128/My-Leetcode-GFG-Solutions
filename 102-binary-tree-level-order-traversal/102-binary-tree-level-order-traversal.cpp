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
  
    void printlevel(TreeNode* root, int level, vector<vector<int>>& lo){
        if(root==NULL){
            return;
        }
        if(lo.size()==level){
            lo.push_back(vector<int>());
        }
        lo[level].push_back(root->val);
        printlevel(root->left,level+1,lo);
        printlevel(root->right,level+1,lo);       
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lo;
        printlevel(root,0,lo);
        return lo;
        
    }
};