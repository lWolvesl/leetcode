#include <stdbool.h>
#include <string.h>

bool checkDistances(char *s, int *distance, int distanceSize)
{
    for (int i = 0; i < strlen(s); i++)
    {
        int site = s[i] - 'a';
        if (distance[i] == -1)
        {
            continue;
        }
        if (site + distance[i] + 1 >= strlen(s) || s[i] != s[i + distance[site] + 1])
        {
            return false;
        }
        distance[i] = -1;
    }
    return true;
}