#include <bits/stdc++.h>

using namespace std;
// O(n log n)

vector<int> LIS(vector<int> &nums)
{
  int n = nums.size();
  vector<int> lis;
  vector<int> answer;

  for (int i = 0; i < n; i++)
  {
    int num = nums[i];
    vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), num);
    long int distance = it - lis.begin();

    if (it == lis.end())
      lis.push_back(num);
    else
      *it = num;

    answer.push_back(distance + 1);
  }

  return answer;
}

int solver(vector<int> &sequence)
{
  vector<int> increasingLIS = LIS(sequence);
  reverse(sequence.begin(), sequence.end());

  vector<int> decreasingLIS = LIS(sequence);
  reverse(decreasingLIS.begin(), decreasingLIS.end());

  int ans = 0;
  for (int i = 0; i < sequence.size(); i++)
  {
    if (increasingLIS[i] == decreasingLIS[i] && (increasingLIS[i] + decreasingLIS[i]) % 2 == 0)
    {
      ans = max(ans, increasingLIS[i] + decreasingLIS[i] - 1);
    }
  }

  return ans;
}

int main()
{

  int m;
  cin >> m;

  vector<int> sequence(m);
  for (int i = 0; i < m; i++)
    cin >> sequence[i];

  cout << solver(sequence) << endl;

  return 0;
}
