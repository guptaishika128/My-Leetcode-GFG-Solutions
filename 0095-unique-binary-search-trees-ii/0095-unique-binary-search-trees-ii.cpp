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
    vector<TreeNode*> allPossibleBST(int start, int end){
         vector<TreeNode *> ans;
        
        // base case
        if (start>end) {
            ans.push_back(NULL);
            return ans;
        }
         // Iterate through all values from start to end to construct left and right subtrees recursively.
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left = allPossibleBST(start,i-1);
            vector<TreeNode*> right = allPossibleBST(i+1,end);
            
            // Loop through all left and right subtrees and connect them to the ith root.
            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(i,l,r);
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
          return allPossibleBST(1,n);
    }
};