#include <iostream>
#include <stack>
using namespace std;

/* You are given the head of a non-empty linked list representing a non-negative integer without leading
zeroes.
Return the head of the linked list after doubling it.

Example 1:
Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence,
the returned linked list represents the number 189 * 2 = 378.

Example 2:
Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999.
Hence, the returned linked list reprersents the number 999 * 2 = 1998.

Constraints:
The number of nodes in the list is in the range [1, 104]
0 <= Node.val <= 9
The input is generated such that the list represents a number that does not have leading zeros, except
the number 0 itself.*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createLLFromArray(int arr[], int n)
{
    if (n == 0)
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *p = head;
    int i = 1;
    while (i < n)
    {
        p->next = new ListNode(arr[i]);
        p = p->next;
        i++;
    }

    return head;
}

void Display(ListNode *head)
{
    if (!head)
    {
        cout << "No data \n";
        return;
    }

    cout << "\n";
    while (head)
    {
        cout << head->val << " , ";
        head = head->next;
    }
    cout << "\n";
}

// METHOD1 -- Reversing the lisked list
ListNode *Reverse(ListNode *head)
{
    ListNode *prev = nullptr, *curr = head;
    while (curr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

ListNode *doubleIt(ListNode *head)
{
    if (!head)
        return nullptr;

    int carry = 0;
    head = Reverse(head);
    ListNode *prev = nullptr;
    ListNode *p = head;
    while (p)
    {
        int prod = (p->val * 2) + carry;
        prev = p;
        p->val = (prod % 10);
        carry = prod / 10;
        p = p->next;
    }

    if (carry)
    {
        prev->next = new ListNode(carry);
    }
    head = Reverse(head);
    return head;
}

// METHOD 2 -- STACK
ListNode *doubleIt2(ListNode *head)
{
    stack<int> stk;
    int cal = 0;
    while (head)
    {
        stk.push(head->val);
        head = head->next;
    }

    ListNode *newHead = nullptr;
    while (!stk.empty() || cal > 0)
    {
        newHead = new ListNode(0, newHead);
        if (!stk.empty())
        {
            int ele = stk.top();
            stk.pop();
            cal += (ele * 2);
        }
        newHead->val = cal % 10;
        cal /= 10;
    }

    return newHead;
}

// METHOD 3 -- RECURSION
int solve(ListNode *head)
{
    if (!head)
        return 0;

    // double the current node and add the carry of the next nodes
    int product = (head->val * 2) + solve(head->next);

    // update current node's value
    head->val = product % 10;

    // return the carry
    return product / 10;
}

ListNode *doubleIt3(ListNode *head)
{
    if (!head)
        return nullptr;

    int carry = solve(head);
    if (carry > 0)
    {
        head = new ListNode(carry, head);
    }

    return head;
}

int main()
{
    int arr[] = {9, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *head1 = createLLFromArray(arr, n);
    Display(head1);
    head1 = doubleIt(head1);
    Display(head1);
    head1 = doubleIt2(head1);
    Display(head1);
    head1 = doubleIt3(head1);
    Display(head1);

    return 0;
}