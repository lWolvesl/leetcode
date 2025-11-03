#include <string>
#include <vector>
#include <iostream>

int minCost(std::string colors, std::vector<int> &neededTime)
{
    int n = colors.size();
    colors += '#';
    int m = 0, count = 0, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        m = std::max(neededTime[i], m);
        count += neededTime[i];
        if (colors[i] == colors[i + 1])
        {
            continue;
        };
        ans += count - m;
        m = 0;
        count = 0;
    }
    return ans;
}

int main()
{
    std::string c = "abaac";
    std::vector<int> need = {1, 2, 3, 4, 5};
    std::cout<<minCost(c, need);
}