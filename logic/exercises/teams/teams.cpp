#include <bits/stdc++.h>

using namespace std;

// Você pode ajudá-los a encontrar a menor diferença possível entre os níveis de habilidades das equipes?

// 20 minutes

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<int> players;
  players.push_back(a);
  players.push_back(b);
  players.push_back(c);
  players.push_back(d);

  sort(players.begin(), players.end());

  int firstTeam = players[0] + players[3];
  int secondTeam = players[1] + players[2];
  int ans = abs(firstTeam - secondTeam);

  cout << ans << endl;

  return 0;
}
