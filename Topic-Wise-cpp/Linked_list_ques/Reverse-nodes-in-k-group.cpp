#include <iostream>
using namespace std;

/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes
is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.



Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000

Follow-up: Can you solve the problem in O(1) extra memory space?

*/

class ListNode
{
public:
    int val;
    ListNode *prev;
    ListNode *next;

    ListNode(int x)
    {
        this->val = x;
        this->next = this->prev = NULL;
    }
};

ListNode *llFromArray(int arr[], int n)
{
    if (n == 0)
        return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;

    int i = 1;
    while (i < n)
    {
        curr->next = new ListNode(arr[i++]);
        curr = curr->next;
    }

    return head;
}

ListNode *reverseLL(ListNode *head)
{
    ListNode *p = head, *q = NULL, *r = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    return q;
}

void print(ListNode *p)
{
    while (p)
    {
        cout << p->val << " , ";
        p = p->next;
    }
    cout << "\n\n";
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || k == 0)
        return head;

    ListNode *dummyHead = new ListNode(-1);
    ListNode *prev = dummyHead, *curr = head, *end = head;

    while (end)
    {
        int len = k;
        ListNode *temp = NULL;
        while (end && len > 0)
        {
            temp = end;
            end = end->next;
            len--;
        }

        if (!end)
        {
            if (len == 0)
            {
                prev->next = reverseLL(curr);
            }
            else
            {
                prev->next = curr;
            }
            break;
        }
        if (temp)
            temp->next = NULL;

        prev->next = reverseLL(curr);
        curr = prev->next;

        while (curr && curr->next)
            curr = curr->next;

        if (curr->next)
            curr->next = end;

        prev = curr;
        curr = end;
    }

    return dummyHead->next;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    ListNode *head = llFromArray(arr, 5);
    print(head);
    head = reverseKGroup(head, 4);
    print(head);
    return 0;
}