#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
int dimensions, start_x, start_y;
int square[MAXN][MAXN];
int visited[110][110];

int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, 1, 0, -1};
int n_flags = 0;

void dfs(int x, int y)
{
  visited[x][y] = 1;
  n_flags++;

  for (int i = 0; i < 4; i++)
  {
    int next_x = x + X[i];
    int next_y = y + Y[i];
    bool validLimits = 0 < next_x && next_x <= dimensions && 0 < next_y && next_y <= dimensions;

    if (validLimits)
      if (visited[next_x][next_y] == 0 && square[next_x][next_y] >= square[x][y])
        dfs(next_x, next_y);
  }
}

int main()
{
  cin >> dimensions >> start_x >> start_y;

  for (int i = 1; i <= dimensions; i++)
    for (int j = 1; j <= dimensions; j++)
      cin >> square[i][j];

  dfs(start_x, start_y);
  cout << n_flags << endl;
  return 0;
}
