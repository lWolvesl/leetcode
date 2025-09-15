#include <string>
#include <iostream>
using namespace std;

int countKConstraintSubstrings(string s, int k)
{
    int a, b;
    int count = 0;
    for (int i = 1; i <= s.length(); i++)
    {
        int j = 0;
        while (j + i <= s.length())
        {
            a = 0;
            b = 0;
            for (int k = j; k < j + i; k++)
            {
                if (s[k] == '0')
                {
                    a++;
                }
                else
                {
                    b++;
                }
            }
            if (a <= k || b <= k)
            {
                count++;
                cout << j << " " << j + i << " " << a << " " << b << endl;
            }
            j++;
        }
    }
    return count;
}