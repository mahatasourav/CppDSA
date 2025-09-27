#include <bits/stdc++.h>
using namespace std;

int PartitionFunc(int arr[], int low, int high)
{
  int pivotVal = arr[low];
  int i = low, j = high;

  while (i < j)
  {
    while (arr[i] <= pivotVal && i <= high - 1)
    {
      i++;
    }
    while (arr[j] > pivotVal && j >= low + 1)
    {
      j--;
    }
    if (i < j)
    {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[low], arr[j]);
  return j;
}

void quick_sort(int arr[], int low, int high)
{
  if (low < high)
  {
    int PIndx = PartitionFunc(arr, low, high);
    quick_sort(arr, low, PIndx - 1);
    quick_sort(arr, PIndx + 1, high);
  }
}
int main()
{
  int n;
  cout << "size of array : \t";
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  quick_sort(arr, 0, n - 1);
  for (int j = 0; j < n; j++)
  {
    cout << arr[j] << "\t";
  }

  return 0;
}