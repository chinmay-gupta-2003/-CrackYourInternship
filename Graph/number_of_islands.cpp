#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool checkIsValid(int row, int col, vector<vector<char>> &grid)
  {
    int rows = grid.size(), cols = grid[0].size();

    if (row >= 0 && row < rows && col >= 0 && col < cols &&
        grid[row][col] == '1')
      return true;

    return false;
  }

  void dfs(int row, int col, vector<vector<char>> &grid,
           vector<vector<bool>> &vis)
  {
    int drow[] = {-1, 0, 0, 1};
    int dcol[] = {0, -1, 1, 0};

    vis[row][col] = true;

    for (int i = 0; i < 4; i++)
    {
      int nrow = row + drow[i];
      int ncol = col + dcol[i];

      if (checkIsValid(nrow, ncol, grid) && !vis[nrow][ncol])
        dfs(nrow, ncol, grid, vis);
    }
  }

  int numIslands(vector<vector<char>> &grid)
  {
    int cnt = 0, rows = grid.size(), cols = grid[0].size();
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        if (grid[i][j] == '1' && !vis[i][j])
        {
          cnt++;
          dfs(i, j, grid, vis);
        }
      }
    }

    return cnt;
  }
};