#include <bits/stdc++.h>
using namespace std;

int main()
{
  // 1️⃣ Read initial time HH:MM
  int h, m;
  char colon;
  cin >> h >> colon >> m; // Input like 2:35

  // 2️⃣ Read number of queries
  int Q;
  cin >> Q;

  // 3️⃣ Read costs A, B, X, Y
  int A, B, X, Y;
  cin >> A >> B >> X >> Y;

  // 4️⃣ Read Q angles into a vector
  vector<int> angles(Q);
  for (int i = 0; i < Q; i++)
  {
    cin >> angles[i];
  }

  // Just to check input
  cout << "Hour: " << h << ", Minute: " << m << "\n";
  cout << "Q: " << Q << "\n";
  cout << "A: " << A << ", B: " << B << ", X: " << X << ", Y: " << Y << "\n";
  cout << "Angles: ";
  for (int angle : angles)
    cout << angle << " ";
  cout << "\n";

  return 0;
}
