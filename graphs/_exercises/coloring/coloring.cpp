#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int n_rows, n_columns;
int board[MAXN][MAXN];

bool is_valid_cell(int x, int y)
{
  if (x > n_rows || y > n_columns || x < 1 || y < 1)
    return false;

  if (board[x][y] == 1)
    return false;

  return true;
}

int ans = 0;
// 8 neighbors -> upper-left diagonal, up, upper-right diagonal, left, right, lower-left diagonal, down, lower-right diagonal
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int x, int y)
{
  // cout << x << " " << y << endl;
  ans++;
  board[x][y] = 1;

  for (int i = 0; i < 8; i++)
  {
    if (is_valid_cell(x + dx[i], y + dy[i]))
      dfs(x + dx[i], y + dy[i]);
  }
}

int main()
{
  cin >> n_rows >> n_columns;

  for (int i = 1; i <= n_rows; i++)
  {
    for (int j = 1; j <= n_columns; j++)
    {
      board[i][j] = 0;
    }
  }

  int x, y, k;
  cin >> x >> y >> k;

  for (int i = 1; i <= k; i++)
  {
    int r, c;
    cin >> r >> c;
    board[r][c] = 1;
  }

  // for (int i = 1; i <= n_rows; i++)
  // {
  //   for (int j = 1; j <= n_columns; j++)
  //   {
  //     cout << board[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // cout << x << " " << y << endl;

  dfs(x, y);

  // Seu programa deve imprimir uma linha contendo o número de quadrados pintados pela criança.
  cout << ans << endl;

  return 0;
}
