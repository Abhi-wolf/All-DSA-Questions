#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

/* You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Constraints:
The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000`*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

void MakeLL(ListNode *head, vector<int> arr)
{
    if (arr.size() == 0)
        return;

    head = new ListNode(arr[0]);
    ListNode *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *p = new ListNode(arr[i]);
        temp->next = p;
    }
}

void printLL(ListNode *p)
{
    cout << endl;
    while (p)
    {
        cout << p->val << " , ";
        p = p->next;
    }
    cout << endl;
}

ListNode *Reverse(ListNode *head)
{
    ListNode *p, *q, *r;
    p = head;
    q = r = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    return q;
}

void reorderList(ListNode *head)
{
    if (!head || !head->next || !head->next->next)
        return;

    ListNode *slow = head, *fast = head, *temp = NULL, *prev = NULL;

    // find middle of the ll
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // even no of nodes
    if (fast->next)
    {
        slow = slow->next;
    }

    // reverse the second half
    slow = Reverse(slow);

    // merge both the halfs
    while (head && slow)
    {
        temp = head->next;
        prev = slow->next;

        head->next = slow;
        slow->next = temp;

        head = temp;
        slow = prev;
    }

    // set the next of the last node to NULL
    if (head && head->next)
        head->next->next = NULL;
}

// using stack
void reorderList2(ListNode *head)
{
    stack<ListNode *> stk;
    unordered_map<ListNode *, bool> visited;

    ListNode *p = head;
    while (p)
    {
        stk.push(p);
        p = p->next;
    }

    p = head;

    while (true)
    {
        ListNode *last = stk.top();
        stk.pop();

        ListNode *next = p->next;
        visited[p] = true;
        if (visited[last])
        {
            p->next = NULL;
            break;
        }

        p->next = last;
        visited[last] = true;
        p = p->next;

        if (visited[next])
        {
            p->next = NULL;
            break;
        }

        p->next = next;
        p = p->next;
    }
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    printLL(head);

    reorderList(head);
    // reorderList2(head);

    printLL(head);
    return 0;
}