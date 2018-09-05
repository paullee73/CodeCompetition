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




class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>> &sol, vector<int> &tmp, unordered_map<int, bool> &used){
        if(tmp.size() == nums.size()){
            sol.push_back(tmp);
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] || i > 0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }
            used[i] = true;
            tmp.push_back(nums[i]);
            helper(nums, sol, tmp, used);
            used[i] = false;
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        vector<int> tmp;
        unordered_map<int, bool> used;
        helper(nums, sol, tmp, used);
        return sol;
    }
};
