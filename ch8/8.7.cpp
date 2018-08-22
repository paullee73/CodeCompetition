#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string insertCharAt(string word, char c, int i)
{
    string start = word.substr(0, i);
    string end = word.substr(i, word.size());
    return start + c + end;
}

vector<string> permutations(string s)
{
    vector<string> permutations;
    if (s.size() == 0)
    {
        permutations.push_back("");
        return permutations;
    }
    char first = s[0];
    string remainder = s.substr(1, s.size());
    vector<string> words = permutations(remainder);
    for (string word : words)
    {
        for (int j = 0; j <= word.length(); j++)
        {
            string s = insertCharAt(word, first, j);
            permutations.push_back(s);
        }
    }
    return permutations;
}

int main()
{
    vector<string> asdf = permutations("123");
    return 0;
}