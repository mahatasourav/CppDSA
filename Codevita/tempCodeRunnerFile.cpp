#include <bits/stdc++.h>
using namespace std;

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main()
{
  int N;
  cin >> N;
  vector<string> compressed(N);
  for (int i = 0; i < N; i++)
    cin >> compressed[i];

  // Step 1: Expand the compressed wall representation into full grid
  vector<vector<char>> wall(N, vector<char>(N));
  for (int i = 0; i < N; i++)
  {
    string row = compressed[i];
    int col = 0;
    for (int j = 0; j < (int)row.size(); j++)
    {
      if (isdigit(row[j]))
      {
        int num = row[j] - '0';
        char brick = row[j + 1];
        for (int k = 0; k < num; k++)
        {
          wall[i][col++] = brick;
        }
        j++; // Skip the brick character
      }
    }
  }

  // Step 2: Find Source (S) and Destination (D)
  pair<int, int> source, dest;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (wall[i][j] == 'S')
        source = {i, j};
      if (wall[i][j] == 'D')
        dest = {i, j};
    }
  }

  // Step 3: BFS to find shortest path using only Green bricks (G)
  queue<pair<int, int>> q;
  vector<vector<int>> dist(N, vector<int>(N, -1));

  q.push(source);
  dist[source.first][source.second] = 0;

  while (!q.empty())
  {
    auto [x, y] = q.front();
    q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      // Check bounds
      if (nx < 0 || ny < 0 || nx >= N || ny >= N)
        continue;

      // Only move to Green bricks or Destination
      if (wall[nx][ny] == 'R' || dist[nx][ny] != -1)
        continue;

      // Can move if it's a Green brick or Destination
      if (wall[nx][ny] == 'G' || wall[nx][ny] == 'D')
      {
        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }

  // Step 4: Output result
  cout << dist[dest.first][dest.second] << endl;
  return 0;
}