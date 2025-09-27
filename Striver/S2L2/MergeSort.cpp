#include <bits/stdc++.h>

using namespace std;
void Merge(vector<int> &arr, int low, int mid, int high)
{
  vector<int> temp;
  int leftt = low;
  int rightt = mid + 1;
  while (leftt <= mid && rightt <= high)
  {
    if (arr[leftt] <= arr[rightt])
    {
      temp.push_back(arr[leftt]);
      leftt++;
    }
    else
    {
      temp.push_back(arr[rightt]);
      rightt++;
    }
  }
  while (leftt <= mid)
  {
    temp.push_back(arr[leftt]);
    leftt++;
  }
  while (rightt <= high)
  {
    temp.push_back(arr[rightt]);
    rightt++;
  }

  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low];
  }
}
void Merge_sort(vector<int> &arr, int low, int high)
{
  if (low >= high)
  {
    return;
  }
  int mid = low + (high - low) / 2;

  Merge_sort(arr, low, mid);
  Merge_sort(arr, mid + 1, high);
  Merge(arr, low, mid, high);
}
int main()
{

  vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
  int n = 7;
  Merge_sort(arr, 0, n - 1);

  for (int j = 0; j < n; j++)
  {
    cout << arr[j] << "\t";
  }

  return 0;
}
