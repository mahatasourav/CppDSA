#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
  int data;
  node *next;
} *head = NULL;

void CreateCLL(int A[], int n)
{
  int i;
  node *t, *last;

  head = new node;
  head->data = A[0];

  head->next = NULL;
  last = head;
  for (i = 1; i < n; i++)
  {
    t = new node;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}
void Display(node *p)
{
  int flag = 0;
  if (p != head || flag == 0)
  {
    flag = 1;
    cout << "->" << p->data;
    Display(p->next);
  }
  flag = 0;
}

int main()
{
  int A[6] = {8, 11, 22, 18, 25, 76};
  CreateCLL(A, 6);
  Display(head);

  return 0;
}