#include <iostream>
using namespace std;

/*
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:
Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within
    the sorted list and inserts it there.
It repeats until no input elements remain.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Constraints:
The number of nodes in the list is in the range [1, 5000].
-5000 <= Node.val <= 5000
*/

class Node
{
public:
    int val;
    Node *next;

    Node()
    {
        this->val = 0;
        this->next = NULL;
    }

    Node(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

Node *InsertAtTail(Node *head, int num)
{
    Node *temp = new Node(num);
    if (head == NULL)
        return temp;

    Node *p = head;
    while (p->next)
        p = p->next;

    p->next = temp;
    return head;
}

//  INSERTION SORT LIST
Node *InsertionSortlist(Node *head)
{
    if (!head)
        return NULL;

    Node *newHead = new Node();
    Node *curr = head;

    while (curr)
    {
        Node *prev = newHead;

        while (prev->next && prev->next->val <= curr->val)
            prev = prev->next;

        Node *temp = curr->next;
        curr->next = prev->next;
        prev->next = curr;

        curr = temp;
    }

    return newHead->next;
}

void Display(Node *p)
{
    while (p)
    {
        cout << p->val << ", ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int arr[] = {-1, 5, 3, 4, 0, 4, 9, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        head = InsertAtTail(head, arr[i]);
    }

    Display(head);
    head = InsertionSortlist(head);
    cout << "\n List after Insertion sort : ";
    Display(head);
    return 0;
}
