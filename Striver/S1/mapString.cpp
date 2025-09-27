#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cout << "Enter your string :\t";
  cin >> s;

  // precompute
  map<char, int> mpp;
  for (int i = 0; i < s.size(); i++)
  {
    mpp[s[i]]++;
  }

  int q;
  cout << "Enter which cherecter frequecny you wanna search here : \t";
  cin >> q;
  while (q--)
  {
    char c;
    cin >> c;
    cout << "the character" << c << "appears \t" << mpp[c] << "\t times here";
  }

  return 0;
}