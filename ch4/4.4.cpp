/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     int depth(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }
//         return max(depth(root->left)+1, depth(root->right)+1);
//     }
    
//     bool isBalanced(TreeNode* root) {
//         if(root == NULL){
//             return true;
//         }
//         int left = depth(root->left);
//         int right = depth(root->right);
//         return isBalanced(root->left) && isBalanced(root->right) && abs(left - right) <= 1;
//     }
// };

class Solution {
public:
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftDepth = helper(root->left);
        if(leftDepth == -1){
            return -1;
        }
        int rightDepth = helper(root->right);
        if(rightDepth == -1){
            return -1;
        }
        if(abs(leftDepth - rightDepth) > 1){
            return -1;
        }
        return max(leftDepth, rightDepth)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }
};
