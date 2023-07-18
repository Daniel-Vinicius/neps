#include <bits/stdc++.h>

using namespace std;

int maxSorries(vector<int> phraseSizes, vector<int> sorriesQuantity, int cardLength)
{
  int N = phraseSizes.size();

  int dp[N + 1][cardLength + 1] = {};
  dp[0][0] = 0;

  for (int i = 1; i <= N; i++)
  {
    int phraseSize = phraseSizes[i - 1];
    int sorryQuantity = sorriesQuantity[i - 1];

    for (int sz = 1; sz <= cardLength; sz++)
    {
      dp[i][sz] = dp[i - 1][sz];

      if (sz >= phraseSize && dp[i - 1][sz - phraseSize] + sorryQuantity > dp[i][sz])
      {
        dp[i][sz] = dp[i - 1][sz - phraseSize] + sorryQuantity;
      }
    }
  }

  return dp[N][cardLength];
}

int main()
{
  int n_testSet = 0;
  int cardLength = 0;

  while (cin >> cardLength && cardLength != 0)
  {
    n_testSet++;
    int n_phrases = 0;
    cin >> n_phrases;

    vector<int> phrasesSizes(n_phrases);
    vector<int> sorriesQuantity(n_phrases);
    for (int i = 0; i < n_phrases; i++)
      cin >> phrasesSizes[i] >> sorriesQuantity[i];

    int ans = maxSorries(phrasesSizes, sorriesQuantity, cardLength);
    cout << "Teste " << n_testSet << endl;
    cout << ans << endl;
    cout << endl;
  }

  return 0;
}
