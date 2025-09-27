#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
} *root = NULL;

void Insert(int key)
{
  struct node *t = root;
  struct node *r, *p;
  if (root == NULL)
  {
    p = new node;
    p->data = key;
    p->left = NULL;
    p->right = NULL;
    root = p;
    return;
  }
  while (t != NULL)
  {
    r = t;
    if (key < t->data)
    {
      t = t->left;
    }
    else if (key > t->data)
    {
      t = t->right;
    }
    else
      return;
  }

  p = new node;
  p->data = key;
  p->left = NULL;
  p->right = NULL;

  if (key < r->data)
  {
    r->left = p;
  }
  else
  {
    r->right = p;
  }
}
node *RInsert(struct node *p, int key)
{
  node *t = NULL;
  if (p == NULL)
  {
    t = new node;
    t->data = key;
    t->left = t->right = NULL;
    return t;
  }

  if (key < p->data)
  {
    p->left = RInsert(p->left, key);
  }
  else if (key > p->data)
  {
    p->right = RInsert(p->right, key);
  }
  return p;
}
void Inorder(node *p)
{
  if (p)
  {
    Inorder(p->left);
    cout << p->data << endl;
    Inorder(p->right);
  }
}
node *Search(int key)
{
  node *t = root;
  while (t)
  {
    if (key == t->data)
    {
      return t;
    }
    else if (key < t->data)
    {
      t = t->left;
    }
    else
    {
      t = t->right;
    }
  }
  return NULL;
}

int main()
{
  node *temp;
  root = RInsert(root, 10);
  RInsert(root, 20);
  RInsert(root, 4);
  RInsert(root, 8);
  RInsert(root, 1);
  RInsert(root, 22);
  Inorder(root);

  if (root == NULL)
  {
    cout << "root is NULL";
  }

  temp = Search(1);

  if (temp)
  {
    cout << "Element is found , data is : " << temp->data;
  }
  else
  {
    cout << "Element can not found it BST";
  }

  return 0;
}