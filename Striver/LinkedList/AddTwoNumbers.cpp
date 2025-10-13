// Problem : add 1 to a number represented as linked list
// Time Complexity : O(n)
// Problem Link : https://leetcode.com/problems/add-two-numbers/
// Video Solution : https://www.youtube.com/watch?si=VYuZYUcaVCrZCgpA&v=XmRrGzR6udg&feature=youtu.be

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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {

    ListNode *dummyNode = new ListNode();
    ListNode *temp = dummyNode;
    int carry = 0;
    while (l1 || l2 || carry)
    {

      int sum = carry;
      if (l1)
      {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2)
      {
        sum += l2->val;
        l2 = l2->next;
      }

      carry = sum / 10;
      sum = sum % 10;
      temp->next = new ListNode(sum);
      temp = temp->next;
    }

    return dummyNode->next;
  }
};
