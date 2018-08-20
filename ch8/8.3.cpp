#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution
{
  public:
    int helper(vector<int> input, int start, int end)
    {
        int mid = (start + end) / 2;
        if (input[mid] == mid)
        {
            return mid;
        }

        int leftIndex = min(input[mid] - 1, mid);
        int left = helper(input, start, leftIndex);

        if (left >= 0)
        {
            return left;
        }

        int rightIndex = max(input[mid] + 1, mid);
        int right = helper(array, rightIndex, end);

        return right;
    }
    int magicIndex(vector<int> input)
    {
        return helper(input, 0, input.size() - 1);
    }
};

int main()
{
    return 0;
}