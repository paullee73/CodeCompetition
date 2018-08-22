#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> countChar(string s)
{
    unordered_map<char, int> freq;
    for (char c : s)
    {
        freq[c]++;
    }
    return freq;
}

void helper(unordered_map<char, int> &freq, vector<string> &perms, int remaining, string prefix)
{
    if (remaining == 0)
    {
        perms.push_back(prefix);
        return;
    }

    for (auto it : freq)
    {
        if (it.second > 0)
        {
            prefix += it.first;
            freq[it.first]--;
            helper(freq, perms, remaining - 1, prefix);
            freq[it.first]++;
        }
    }
}

vector<string> permutations(string s)
{
    vector<string> perms;
    unordered_map<char, int> freq = countChar(s);
    helper(freq, perms, s.size(), "");
    return perms;
}

int main()
{
    vector<string> asdf = permutations("122");
    for (string s : asdf)
    {
        cout << s << endl;
    }
}