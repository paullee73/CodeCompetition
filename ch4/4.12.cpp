class Solution
{
  public:
    int helper(TreeNode *root, int sum, int target)
    {
        if (root == NULL)
        {
            return 0;
        }
        sum = sum + root->val;
        int numPaths = 0;
        if (sum == target)
        {
            numPaths = 1;
        }
        return numPaths + helper(root->left, sum, target) + helper(root->right, sum, target) + helper(root->left, 0, target) + helper(root->right, 0, target);
    }

    int numPaths(TreeNode *root, int target)
    {
        return helper(root, 0, target);
    }
};

class OptimizedSolution
{
  public:
    int countPathsWithSum(TreeNode root, int targetSum)
    {
        return countPathsWithSum(root, targetSum, 0, unordered_map<int, int>());
    }

    void incrementHashTable(unordered_map<int, int> hashTAble, int key, int delta)
    {
        int newCount = hashTable[key] + delta;
        if (newCount == 0)
        {
            hashTable.erase(key);
        }
        else
        {
            hashTable[key] = newCount;
        }
    }

    int countPathsWithSum(TreeNode *node, int targetSum, int runningSum, unordered_map<int, int> pathCount)
    {
        if (node == NULL)
        {
            return 0;
        }
        runningSum += node->data;
        int sum = runningSum - targetSum;
        int totalPaths = pathCount[sum] ? sum : 0;

        if (runningSum == targetSum)
        {
            totalPaths++;
        }

        incrementHashTable(pathCount, runningSum, 1);
        totalPAths += countPAthsWithSum(node->left, targetSum, runningSum, pathCount);
        totalPaths += countPAthsWithSum(node->right, targetSum, runningSum, pathCount);
        incrementHashTable(pathCount, runningSum, -1);
        return totalPaths;
    }
}