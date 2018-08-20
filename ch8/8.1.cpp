#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    int helper(int steps, int arr[])
    {
        if (steps < 0)
        {
            return 0;
        }
        if (steps == 0)
        {
            return 1;
        }
        if (arr[steps] == 0)
        {
            arr[steps] = helper(steps - 1, arr) + helper(steps - 2, arr) + helper(steps - 3, arr);
        }
        return arr[steps];
    }
    int numWays(int steps)
    {
        int param[steps];
        return helper(steps, param);
    }
};

int main()
{
    return 0;
}