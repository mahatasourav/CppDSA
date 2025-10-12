
#include <bits/stdc++.h>
using namespace std;

int R,
    C;
vector<string> g;

bool ok(int r, int c)
{
  return r >= 0 && r < R && c >= 0 && c < C && g[r][c] == '.';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C;
  g.resize(R);
  for (int i = 0; i < R; i++)
    cin >> g[i];

  string s;
  cin >> s;

  int dr[4] = {-1, 0, 1, 0};
  int dc[4] = {0, 1, 0, -1};

  unordered_set<int> endpos;

  for (int r0 = 0; r0 < R; ++r0)
  {
    for (int c0 = 0; c0 < C; ++c0)
    {
      if (g[r0][c0] != '.')
        continue;

      for (int d0 = 0; d0 < 4; ++d0)
      {
        int r = r0, c = c0, d = d0;
        bool bad = false;

        for (char ch : s)
        {
          if (ch == 'L')
            d = (d + 3) & 3;
          else if (ch == 'R')
            d = (d + 1) & 3;
          else
          { // 'S'
            r += dr[d];
            c += dc[d];
            if (!ok(r, c))
            {
              bad = true;
              break;
            }
          }
        }

        if (!bad)
          endpos.insert(r * C + c);
      }
    }
  }

  if (endpos.empty())
    cout << "Impossible";
  else
    cout << endpos.size();

  return 0;
}
