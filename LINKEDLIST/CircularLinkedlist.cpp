#include <iostream>

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
  head->next = head; // Initialize circular link
  last = head;

  for (i = 1; i < n; i++)
  {
    t = new node;
    t->data = A[i];
    t->next = head; // Maintain circular connection
    last->next = t;
    last = t;
  }
}

void Display(node *p)
{
  if (p == NULL)
    return;

  node *temp = p;
  do
  {
    cout << "->" << temp->data;
    temp = temp->next;
  } while (temp != head);

  cout << endl;
}

int main()
{
  int A[6] = {8, 11, 22, 18, 25, 76};
  CreateCLL(A, 6);
  Display(head);

  return 0;
}
