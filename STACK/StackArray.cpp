#include <stdlib.h>
#include <iostream>

using namespace std;

struct StackArray
{
  int size;
  int top;
  int *S;
};

void CreateStackAraay(struct StackArray *st)
{
  cout << "Enter the size of stack :";
  cin >> st->size;
  st->top = -1;
  st->S = new int;
}
void Display(struct StackArray st)
{
  if (st.top == -1)
  {
    cout << "Stack has no element";
  }
  else
  {
    cout << "Stack's elements are : ";
    for (int i = st.top; i >= 0; i--)
    {
      cout << st.S[i] << "\n";
    }
    cout << "\n";
  }
}

void Push(struct StackArray *st, int x)
{
  if (st->top == st->size - 1)
  {
    cout << "Stack is overflow";
  }
  else
  {
    st->top++;
    st->S[st->top] = x;

    cout << st->S[st->top] << "Pushed to Stack \n";
  }
}
int Pop(struct StackArray *st)
{
  int x = -1;
  if (st->top == -1)
  {
    cout << "Stack has no element";
  }
  else
  {
    x = st->S[st->top];
    st->top--;
  }
  return x;
}
int main()
{
  struct StackArray st;

  CreateStackAraay(&st);

  Push(&st, 10);
  Push(&st, 20);
  Push(&st, 30);
  Push(&st, 40);
  int x = Pop(&st);
  cout << "Deleted element from stack is :" << x << "\n";
  Display(st);

  return 0;
}