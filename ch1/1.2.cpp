#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isPermutation(string a, string b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a.size() != b.size())
    {
        return false;
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    bool a = isPermutation("hello", "what");
    bool b = isPermutation("hello", "hello");
    cout << a << endl;
    cout << b << endl;
    return 0;
}