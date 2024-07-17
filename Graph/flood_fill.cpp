#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isValid(int row, int col, vector<vector<int>> &image, int preColor)
  {
    int rows = image.size(), cols = image[0].size();

    if (row >= 0 && row < rows && col >= 0 && col < cols &&
        image[row][col] == preColor)
      return true;

    return false;
  }

  void dfs(int row, int col, vector<vector<int>> &image,
           vector<vector<bool>> &vis, int color, int preColor)
  {
    vis[row][col] = true;
    image[row][col] = color;

    int drow[] = {-1, 0, 0, 1};
    int dcol[] = {0, -1, 1, 0};

    for (int i = 0; i < 4; i++)
    {
      int nrow = row + drow[i];
      int ncol = col + dcol[i];

      if (isValid(nrow, ncol, image, preColor) && !vis[nrow][ncol])
        dfs(nrow, ncol, image, vis, color, preColor);
    }
  }

  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color)
  {
    int rows = image.size(), cols = image[0].size(),
        preColor = image[sr][sc];

    vector<vector<bool>> vis(rows, vector<bool>(cols, false));

    dfs(sr, sc, image, vis, color, preColor);

    return image;
  }
};