#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int climbStairsTopDown(int n, vector<int> &dp)
  {
    if (n < 0)
      return 0;

    if (n == 0 || n == 1)
      return 1;

    if (dp[n] != -1)
      return dp[n];

    int step1 = climbStairsTopDown(n - 1, dp);
    int step2 = climbStairsTopDown(n - 2, dp);

    return dp[n] = step1 + step2;
  }

  int climbStairsTabulation(int n)
  {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }

  int climbStairsOptimized(int n)
  {
    if (n <= 1)
      return 1;

    int a = 1, b = 1, c;

    for (int i = 2; i <= n; i++)
    {
      c = b + a;

      a = b;
      b = c;
    }

    return c;
  }

  int climbStairs(int n)
  {
    // vector<int> dp(n + 1, -1);

    // return climbStairsTopDown(n, dp);

    // return climbStairsTabulation(n);

    return climbStairsOptimized(n);
  }
};