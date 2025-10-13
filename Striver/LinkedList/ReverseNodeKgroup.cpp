
// Problem :Reverse Nodes in k-Group
// Time Complexity :
// Problem Link : https://leetcode.com/problems/reverse-nodes-in-k-group/description/
// Video Solution : https://www.youtube.com/watch?si=_jFghHKX4eaK36a1&v=lIar1skcQYI&feature=youtu.be

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
  ListNode *reverseList(ListNode *head)
  {
    ListNode *last = nullptr;
    ListNode *temp = head;
    while (temp != NULL)
    {
      ListNode *Main = temp->next;
      temp->next = last;
      last = temp;
      temp = Main;
    }
    ListNode *newHead = last;
    return newHead;
  }
  ListNode *getKthNode(ListNode *temp, int k)
  {
    k -= 1;
    while (temp != NULL && k > 0)
    {
      k--;
      temp = temp->next;
    }
    return temp;
  }
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    ListNode *temp = head;
    ListNode *prevLast = NULL;

    while (temp)
    {
      ListNode *kthNode = getKthNode(temp, k);
      if (kthNode == NULL)
      {
        if (prevLast)
          prevLast->next = temp;
        break;
      }
      ListNode *nextNode = kthNode->next;
      kthNode->next = NULL;
      reverseList(temp);
      if (temp == head)
        head = kthNode;
      else
        prevLast->next = kthNode;

      prevLast = temp;
      temp = nextNode;
    }

    return head;
  }
};