#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isUnique(string a)
{
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size() - 1; i++)
	{
		if (a[i] == a[i + 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cout << "hello" << endl;
	bool a = isUnique("hello");
	cout << a << endl;
	return 0;
}