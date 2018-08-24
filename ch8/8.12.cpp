#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    bool isValid(vector<string> &tmp, int row, int col, int n)
    {
        for (int i = 0; i != row; i++)
        {
            if (tmp[i][col] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (tmp[i][j] == 'Q')
            {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (tmp[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

    void helper(vector<string> &tmp, vector<vector<string>> &sol, int row, int &n)
    {
        if (row == n)
        {
            sol.push_back(tmp);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isValid(tmp, row, col, n))
            {
                tmp[row][col] = 'Q';
                helper(tmp, sol, row + 1, n);
                tmp[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> tmp(n, string(n, '.'));
        vector<vector<string>> sol;
        helper(tmp, sol, 0, n);
        return sol;
    }
};