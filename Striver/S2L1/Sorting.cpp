#include <bits/stdc++.h>

using namespace std;

void selectionsort(int arr[], int n)
{
  for (int i = 0; i <= n - 2; i++)
  {
    int mini = i;
    for (int j = i; j < n; j++)
    {
      if (arr[mini] > arr[j])
      {
        int temp;
        temp = arr[mini];
        arr[mini] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void bubble_sort(int arr[], int n)
{
  for (int i = n - 1; i >= 1; i--)
  {
    int didSwap = 0;
    for (int j = 0; j <= i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp;
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        didSwap = 1;
      }
    }
    if (didSwap == 0)
    {
      break;
    }
  }
}
void insertionn_sort(int arr[], int n)
{
  for (int i = 0; i <= n - 1; i++)
  {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
      int temp = arr[j - 1];
      arr[j - 1] = arr[j];
      arr[j] = temp;
      j--;
    }
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
  insertionn_sort(arr, n);
  for (int j = 0; j < n; j++)
  {
    cout << arr[j] << "\t";
  }

  return 0;
}
