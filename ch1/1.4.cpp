#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isPalindromePermutation(string s)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    int numOdds = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if ((it->second % 2) != 0)
        {
            numOdds++;
        }
    }
    if ((numOdds & 2) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    bool a = isPalindromePermutation("hello");
    cout << a << endl;
    return 0;
}