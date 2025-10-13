
// Problem : Rotate List
// Time Complexity : O(N)
// Problem Link : https://leetcode.com/problems/rotate-list/
// Video Solution : https://www.youtube.com/watch?v=uT7YI7XbTY8

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  int lenOfLL(ListNode *&tail)
  {
    int len = 1;
    while (tail->next != NULL)
    {
      len++;
      tail = tail->next;
    }
    return len;
  }
  ListNode *rotateRight(ListNode *head, int k)
  {
    if (head == NULL)
      return NULL;

    ListNode *tail = head;
    ListNode *prev = head;

    int len = lenOfLL(tail);
    k = k % len;
    int dis = len - k - 1;
    while (prev && dis > 0)
    {
      dis--;
      prev = prev->next;
    }
    if (prev == tail)
      return head;
    ListNode *newHead = prev->next;
    prev->next = NULL;
    tail->next = head;
    return newHead;
  }
};