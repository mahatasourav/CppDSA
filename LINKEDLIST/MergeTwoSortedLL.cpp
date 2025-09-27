#include <bits/stdc++.h>

using namespace std;

struct Node
{
  int data;
  Node *next;

} *Head1 = NULL, *Head2 = NULL, *Head3 = NULL;

void CreateLL1(int A[], int n)
{
  int i = 0;
  Node *t, *last;
  Head1 = new Node;
  Head1->data = A[i];
  Head1->next = NULL;
  last = Head1;
  for (i = 1; i < n; i++)
  {
    t = new Node;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
  cout << "Linked List Created Sucessfully \n";
}
void CreateLL2(int A[], int n)
{
  int i = 0;
  Node *t, *last;
  Head2 = new Node;
  Head2->data = A[i];
  Head2->next = NULL;
  last = Head2;
  for (i = 1; i < n; i++)
  {
    t = new Node;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
  cout << "LinkedList2 Created Sucessfully \n";
}

void MergeSortedLL(Node *x, Node *y)
{
  Node *last;
  if (x->data <= y->data)
  {
    Head3 = last = x;
    x = x->next;
    Head3->next = NULL;
  }
  else
  {
    Head3 = last = y;
    y = y->next;
    Head3->next = NULL;
  }

  while (x && y)
  {
    if (x->data <= y->data)
    {
      last->next = x;
      last = x;
      x = x->next;
      last->next = NULL;
    }
    else
    {
      last->next = y;
      last = y;
      y = y->next;
      last->next = NULL;
    }
  }
  if (x)
  {
    last->next = x;
  }
  if (y)
  {
    last->next = y;
  }
}

void Display(Node *p)
{
  while (p)
  {
    cout << "->" << p->data;
    p = p->next;
  }
  cout << "\n";
}
int main()
{
  int A1[6] = {2, 4, 5, 7, 8, 9};
  int A2[7] = {1, 3, 5, 6, 7, 12, 14};

  CreateLL1(A1, 6);
  CreateLL2(A2, 7);
  Display(Head1);
  Display(Head2);

  MergeSortedLL(Head1, Head2);
  Display(Head3);

  return 0;
}