#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cout << "How many size array do you want here : ";
  cin >> n;
  int arr[n];
  cout << "Insert element into array :";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  // precompute
  int hash[1000000] = {0};
  for (int j = 0; j < n; j++)
  {
    hash[arr[j]] += 1;
  }

  int q;
  cout << "how many element do you want to search :";
  cin >> q;
  while (q--)
  {
    int number;
    cin >> number;

    cout << number << "this is " << hash[number] << "times here." << endl;
  }

  return 0;
}