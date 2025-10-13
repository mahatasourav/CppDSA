// Problem : Delete all occurrences of a key in DLL
// Time Complexity : O(n)
// Problem Link : https://takeuforward.org/plus/dsa/problems/delete-all-occurrences-of-a-key-in-dll
// Video Solution : https://www.youtube.com/watch?si=tCYshBRi1upMqSVz&v=Mh0NH_SD92k&feature=youtu.be

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
  ListNode *deleteAllOccurrences(ListNode *head, int target)
  {
    if (!head)
      return nullptr;
    ListNode *temp = head;

    while (temp)
    {
      if (temp->val == target)
      {
        ListNode *delNode = temp;
        temp = temp->next;
        if (delNode->prev == NULL) // case 1 : deleting head
        {
          head = delNode->next;
          if (head)
            head->prev = NULL;
        }
        else if (delNode->next == NULL) // case 2 : deleting tail
        {
          delNode->prev->next = NULL;
        }
        else // case 3 : deleting mid target matching elements
        {
          delNode->prev->next = delNode->next;
          delNode->next->prev = delNode->prev;
        }

        delete delNode;
      }

      else
      {
        temp = temp->next;
      }
    }
    return head;
  }
};