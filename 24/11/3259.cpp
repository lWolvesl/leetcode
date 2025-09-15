#include <vector>
#include <iostream>
#include "math.h"

using namespace std;

// 3259. 能量提升
// 动态规划+贪心 递推式：dp[i] += max(now[i-1], next[i-2])
long long maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB)
{
    int n = energyDrinkA.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    dp[1][0] = energyDrinkA[0];
    dp[1][1] = energyDrinkB[0];
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = energyDrinkA[i - 1] + max(dp[i - 1][0], dp[i - 2][1]);
        dp[i][1] = energyDrinkB[i - 1] + max(dp[i - 1][1], dp[i - 2][0]);
    }
    return max(dp[n][0], dp[n][1]);
}

long long maxEnergyBoost(int* energyDrinkA, int energyDrinkASize, int* energyDrinkB, int energyDrinkBSize) {
    int n = energyDrinkASize;
    long long **dp = (long long **)malloc(sizeof(long long *) * 2);
    dp[0] = (long long *)malloc(sizeof(long long) * (n + 1));
    dp[1] = (long long *)malloc(sizeof(long long) * (n + 1));
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[0][1] = energyDrinkA[0];
    dp[1][1] = energyDrinkB[0];
    for (int i = 2; i <= n; i++)
    {
        dp[0][i] = energyDrinkA[i-1] + fmax(dp[0][i-1], dp[1][i-2]);
        dp[1][i] = energyDrinkB[i-1] + fmax(dp[1][i-1], dp[0][i-2]);
    }
    return fmax(dp[0][n], dp[1][n]);
}


// 空间优化
long long maxEnergyBoost1(int* energyDrinkA, int energyDrinkASize, int* energyDrinkB, int energyDrinkBSize) {
    int n = energyDrinkASize;
    long long tmp[3]={energyDrinkA[0],energyDrinkB[0],energyDrinkA[0]};
    for (int i = 1; i < energyDrinkASize; i++) {
        tmp[0]=fmax(tmp[0]+energyDrinkA[i],tmp[1]);
        tmp[1]=fmax(tmp[1]+energyDrinkB[i],tmp[2]);
        tmp[2]=tmp[0];
    }
    return fmax(tmp[0],tmp[1]);
}