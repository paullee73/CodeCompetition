#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

//open >= closed
//pairs > 0
//end: open == closed, pairs == n

void helper(int index, int open, int closed, char *arr, vector<string> &perm)
{
    if (closed < open || open < 0)
    {
        return;
    }
    if (open == 0 && closed == 0)
    {
        perm.push_back(string(arr));
    }
    else
    {
        arr[index] = '(';
        helper(index + 1, open - 1, closed, arr, perm);

        arr[index] = ')';
        helper(index + 1, open, closed - 1, arr, perm);
    }
}

vector<string> parens(int n)
{
    vector<string> sol;
    char arr[n * 2];
    helper(0, n, n, arr, sol);
    return sol;
}

int main()
{
    vector<string> sol = parens(4);
    for (string s : sol)
    {
        cout << s << endl;
    }
}