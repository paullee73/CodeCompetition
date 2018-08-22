#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution
{
  public:
    moveDisks(int n, int source, int aux, int dest)
    {
        while (n > 0)
        {
            moveDisks(n - 1, source, dest, aux);
            moveTop(origin, dest);
            moveDisks(n - 1, aux, source, dest);
        }
    }
};