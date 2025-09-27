#include <iostream>

using namespace std;

int binarySearchItreative(int arr[], int size, int key)
{

  int low = 0, high = size - 1;
  int mid;
  while (low <= high)
  {
    mid = low + high / 2;
    if (arr[mid] == key)
    {
      return mid;
    }

    else if (arr[mid] < key)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

// int linearSearch( int arr[] , int n, int key)
// {

// }
int main()
{
  int arr[15] = {3, 5, 7, 9, 12, 14, 16, 18, 23, 28, 29, 30, 35, 40, 43};
  int size = sizeof(arr) / sizeof(arr[0]);
  int key;
  cout << "which element you want to search for : \t";
  cin >> key;
  int ele = binarySearchItreative(arr, size, key);

  ele == -1 ? cout << "elememt not found" : cout << "at index : \t" << ele;

  return 0;
}