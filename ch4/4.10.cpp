/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    int getRandomNode()
    {
        if (root == NULL)
        {
            return -1;
        }
        int count = rand() % (root->children + 1);
        return randomNode(root, count);
    }

    int randomNode(Node *root, int count)
    {
        if (count == root.children)
        {
            return root.val;
        }
        if (count < root.children)
        {
            return randomNode(root->left, count);
        }
        return randomNode(root->right, count - root->left->children - 1);
    }
};