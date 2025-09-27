#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cout << "Enter a string : \n";
  cin >> s;

  // precompute

  int hashh[256] = {0};
  for (int i = 0; i < s.size(); i++)
  {
    hashh[s[i]]++;
  }

  int q;
  cout << "how many character you wanna check\n";
  cin >> q;
  cout << "now enter character to check how many times it ocuurs in your string:\t";
  while (q--)
  {
    char c;
    cin >> c;
    cout << "hash valur of , " << c << "\tis : \t" << hashh[c] << endl;
  }

  return 0;
}