// Problem : add 1 to a number represented as linked list
// Time Complexity : O(n)
// Problem Link : https://takeuforward.org/plus/dsa/problems/add-one-to-a-number-represented-by-ll
// Video Solution : https://www.youtube.com/watch?si=uRgU9S4r5cVmnUy7&v=aXQWhbvT3w0&feature=youtu.be

#include <bits/stdc++.h>
using namespace std;

/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution
{
public:
  int helper(ListNode *temp)
  {
    if (temp == NULL)
      return 1;
    int carry = helper(temp->next);
    temp->val = temp->val + carry;
    if (temp->val < 10)
    {
      return 0;
    }
    temp->val = 0;
    return 1;
  }
  ListNode *addOne(ListNode *head)
  {
    int carry = helper(head);
    if (carry == 1)
    {
      // add one newNode
      ListNode *newNode = new ListNode(1, head);
      return newNode;
    }
    return head;
  }
};