#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool oneAway(string a, string b)
{
    if (a.size() == b.size())
    {
        int diff = 0;
	bool foundDifference = false;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
		if(foundDifference){
		   return false;
	    	{
		foundDifference = true;
            }
        }
	return true;
    }
    else
    {
        string x;
        string y;
        int diff = 0;
        if (a.size() > b.size())
        {
            x = a;
            y = b;
        }
        else
        {
            x = b;
            y = a;
        }
        int xL = 0;
        int yL = 0;
        while (xL < x.size() && yL < y.size())
        {
            if (x[xL] != y[yL])
            {
                if (xL != yL)
                {
                    return false;
                }
                xL++;
            }
            else
            {
                xL++;
                yL++;
            }
        }
        return true;
    }
}

int main()
{
    bool a = oneAway("hello", "hedlo");
    cout << a << endl;
    return 0;
}
