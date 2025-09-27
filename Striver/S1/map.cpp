#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cout << "Enter how many size array you wanna :";
  cin >> n;
  int arr[n];
  map<int, int> mpp;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    mpp[arr[i]]++;
  }

  int q;
  cout << "how many times you wanna to check :";
  cin >> q;

  while (q--)
  {
    int number;
    cout << "enter what you want to search : \t";
    cin >> number;

    cout << number << "  is in that map \t" << mpp[number] << "\ttimes in the map" << endl;
  }

  return 0;
}