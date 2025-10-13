
// Problem :Remove duplicated from sorted DLL
// Time Complexity :
// Problem Link : https://takeuforward.org/plus/dsa/problems/remove-duplicated-from-sorted-dll
// Video Solution : https://www.youtube.com/watch?v=YJKVTnOJXSY

/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution
{
public:
  ListNode *removeDuplicates(ListNode *head)
  {
    ListNode *temp = head;

    while (temp)
    {
      ListNode *left = temp;
      ListNode *right = temp->next;

      while (right && left->val == right->val)
      {
        ListNode *delNode = right;
        right = right->next;
        delete delNode;
      }
      left->next = right;
      if (right)
        right->prev = left; // in the last when right will be null then we can not set right->prev = NULL
      temp = right;
    }
    return head;
  }
};