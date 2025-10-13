// Problem :Find Pairs with Given Sum in Doubly Linked List
// Time Complexity : O(n)
// Problem Link : https://takeuforward.org/plus/dsa/problems/find-pairs-with-given-sum-in-doubly-linked-list
// Video Solution : https://www.youtube.com/watch?v=YitR4dQsddE

/*
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution
{
public:
  vector<vector<int>> findPairsWithGivenSum(ListNode *head, int target)
  {
    vector<vector<int>> result;
    if (!head)
      return result;

    // find tail
    ListNode *tail = head;
    while (tail->next)
      tail = tail->next;

    ListNode *left = head;
    ListNode *right = tail;

    while (left != right && left->prev != right)
    {
      int sum = left->val + right->val;
      if (sum == target)
      {
        result.push_back({left->val, right->val});
        left = left->next;
        right = right->prev;
      }
      else if (sum < target)
      {
        left = left->next;
      }
      else
      {
        right = right->prev;
      }
    }

    return result;
  }
};