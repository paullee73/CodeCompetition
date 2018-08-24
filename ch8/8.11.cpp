#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

int helper(int cents, int index, int map[][4])
{
    if (map[cents][index] > 0)
    {
        return map[cents][index];
    }
    if (index >= 3)
    {
        return 1;
    }
    int coins[] = {25, 10, 5, 1};
    int denom = coins[index];
    int ways = 0;

    for (int i = 0; i * denom <= cents; i++)
    {
        ways += helper(cents - i * denom, index + 1, map);
    }
    map[cents][index] = ways;
    return ways;
}

int numWays(int cents)
{
    int map[cents + 1][4];
    return helper(cents, 0, map);
}

int main()
{
    int n = numWays(10);
    cout << n << endl;
}