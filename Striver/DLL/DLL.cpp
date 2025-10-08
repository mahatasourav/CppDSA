#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;   // Data stored in the node
  Node *next; // Pointer to the next node in the list (forward direction)
  Node *back; // Pointer to the previous node in the list (backward direction)

  // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
  Node(int data1, Node *next1, Node *back1)
  {
    data = data1;
    next = next1; // Similar to a singly linked list, but now with a 'back' pointer.
    back = back1; // Addition of 'back' pointer for the doubly linked list.
  }

  // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
  Node(int data1)
  {
    data = data1;
    next = nullptr; // Similar to a singly linked list.
    back = nullptr; // Addition of 'back' pointer initialization.
  }
};
Node *convertArr2DLL(vector<int> &arr)
{
  Node *head = new Node(arr[0]);

  Node *prev = head;

  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}
Node *deleteHead(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    // Return NULL if the list is empty or contains only one element
    return nullptr;
  }
  Node *prev = head;
  head = head->next;
  head->back = nullptr;
  prev->next = nullptr;

  return head;
}
Node *deleteTail(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    // If the list is empty or has only one node, return null
    return nullptr;
  }
  Node *tail = head;
  while (tail->next != nullptr)
  {
    tail = tail->next;
  }
  Node *prev = tail->back;
  prev->next = nullptr;
  tail->back = nullptr;
  delete (tail);
  return head;
}
Node *removeKElement(Node *head, int k)
{
  if (head == nullptr)
  {
    return NULL;
  }
  int cnt = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    cnt++;
    if (cnt == k)
      break;
    temp = temp->next;
  }
  if (temp == nullptr) // k is out of bounds
    return head;
  Node *prev = temp->back;
  Node *front = temp->next;

  if (prev == nullptr && front == nullptr)
  {
    delete (temp);
    return NULL;
  }
  else if (prev == nullptr)
  {
    head = deleteHead(head);
  }
  else if (front == nullptr)
  {
    head = deleteTail(head);
  }
  else
  {
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    free(temp);
  }
  return head;
}
void deleteNode(Node *temp)
{
  Node *prev = temp->back;
  Node *front = temp->next;

  if (front == nullptr)
  {
    prev->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return;
  }
  prev->next = front;
  front->back = prev;
  temp->next = nullptr;
  temp->back = nullptr;
  free(temp);
}
void print(Node *head)
{
  while (head != nullptr)
  {
    // Print the data in the current node
    cout << head->data << " ";
    // Move to the next node
    head = head->next;
  }
}

Node *insertBeforeHead(Node *head, int val)
{
  Node *newHead = new Node(val, head, nullptr);

  head->back = newHead;
  return newHead;
}

Node *insertBeforeTail(Node *head, int val)
{

  if (head->next == nullptr)
    return insertBeforeHead(head, val);
  Node *tail = head;
  while (tail->next != nullptr)
  {
    tail = tail->next;
  }
  Node *prev = tail->back;
  Node *newNode = new Node(val, tail, prev);
  prev->next = newNode;
  tail->back = newNode;
  return head;
}
Node *insetAtKthPos(Node *head, int k, int val)
{
  if (k == 1)
    return insertBeforeHead(head, val);
  Node *temp = head;
  int cnt = 0;
  while (temp != nullptr)
  {
    cnt++;
    if (cnt == k)
      break;
    temp = temp->next;
  }
  Node *prev = temp->back;
  Node *newNode = new Node(val, temp, prev);
  prev->next = newNode;
  temp->back = newNode;
  return head;
}
void insertBeforeNode(Node *node, int val)
{
  Node *prev = node->back;
  Node *newNode = new Node(val, node, prev);
  prev->next = newNode;
  node->back = newNode;
}
Node *reverseDLL(Node *head)
{
  if (head == NULL || head->next == nullptr)
    return head;

  Node *last = NULL;
  Node *current = head;
  while (current != NULL)
  {
    last = current->back;
    current->back = current->next;
    current->next = last;
    current = current->back;
  }
  Node *newHead = last->back;
  return last->back;
}
int main()
{
  vector<int> arr = {1, 5, 7, 6, 9};

  Node *head = convertArr2DLL(arr);
  // head = removeKElement(head, 1);
  // deleteNode(head->next->next->back);
  // head = insetAtKthPos(head, 1, 89);
  // insertBeforeNode(head->next, 10);
  head = reverseDLL(head);

  print(head);
  return 0;
}