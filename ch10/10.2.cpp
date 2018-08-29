#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        vector<vector<string>> sol;
        unordered_map<int, vector<string>> map;
        for (int i = 0; i < strs.size(); i++)
        {
            int primeHash = 1;
            for (char c : strs[i])
            {
                primeHash *= prime[c - 'a'];
            }
            if (map.find(primeHash) != map.end())
            {
                map[primeHash].push_back(strs[i]);
            }
            else
            {
                vector<string> newVec;
                newVec.push_back(strs[i]);
                map[primeHash] = newVec;
            }
        }
        for (auto it = map.begin(); it != map.end(); it++)
        {
            sol.push_back(it->second);
        }
        return sol;
    }
};