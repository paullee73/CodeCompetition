#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution
{
  public:
    int helper(int smaller, int bigger, int memo[])
    {
        if (smaller == 0)
        {
            return 0;
        }
        if (smaller == 1)
        {
            return bigger;
        }
        if (memo[smaller] > 0)
        {
            return memo[smaller];
        }

        int s = s / 2;
        int side1 = helper(s, bigger, memo);
        int side2 = side1;
        if (smaller % 2 == 1)
        {
            return helper(smaller - s, bigger, memo);
        }
        memo[smaller] = side1 + side2;
        return memo[smaller];
    }

    int recursiveMultiply(int a, int b)
    {
        int bigger = a > b ? a : b;
        int smaller = a < b ? a : b;
        int memo[smaller + 1];
        return helper(smaller, bigger, memo);
    }
};

class OptimizedSolution
{
  public:
    int recursiveMultiply(int a, int b)
    {
        int bigger = a > b ? a : b;
        int smaller = a < b ? a : b;
        return helper(smaller, bigger);
    }

    int helper(int smaller, int bigger)
    {
        if (smaller == 0)
        {
            return 0;
        }
        if (smaller == 1)
        {
            return bigger;
        }
        int s = smaller / 2;
        int halfProd = helper(s, bigger);

        if (smaller % 2 == 0)
        {
            return halfProd + halfProd;
        }
        else
        {
            return helfProd + halfProd + bigger;
        }
    }
}