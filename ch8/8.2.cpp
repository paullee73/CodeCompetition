#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution
{
  public:
    bool findPath(vector<vector<int>> grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int xDir[] = {1, 0};
        int yDir[] = {0, -1};
        bool traversed[rows][cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                traversed[i][j] = false;
            }
        }

        queue<int> xTraversed;
        queue<int> yTraversed;
        xTraversed.push(0);
        yTraversed.push(0);
        while (!queue.empty())
        {
            int currX = xTraversed.back();
            int currY = yTraversed.back();
            if (currX == rows - 1 && currY == cols - 1)
            {
                return true;
            }
            xTraversed.pop();
            yTraversed.pop();
            if (!traversed[currX][currY])
            {
                traversed[currX][currY] = true;
                for (int i = 0; i < sizeof(xDir); i++)
                {
                    if (currX + xDir[i] < rows && currX + xDir[i] >= 0 && currY + yDir[i] < cols && currY + yDir[i] >= 0)
                    {
                        xTraversed.push(xCurr + xDir[i]);
                        yTraversed.push(yCurr + yDir[i]);
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}