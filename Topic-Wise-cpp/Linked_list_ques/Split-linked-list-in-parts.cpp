#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

ListNode *createLL(vector<int> arr)
{
    if (arr.size() == 0)
        return NULL;

    ListNode *head = new ListNode(arr[0]);
    ListNode *tail = head;

    for (int i = 1; i < arr.size(); i++)
    {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }

    return head;
}

void Display(ListNode *head)
{
    while (head)
    {
        cout << head->val << ", ";
        head = head->next;
    }
    cout << endl;
}

/*
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
The length of each part should be as equal as possible: no two parts should have a size differing by more than one.
This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a
size greater than or equal to parts occurring later.
Return an array of the k parts.

Example 1:
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Example 2:
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size
than the later parts.

Constraints:
The number of nodes in the list is in the range [0, 1000].
0 <= Node.val <= 1000
1 <= k <= 50
*/

int lengthLL(ListNode *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }

    return len;
}

// TC -- O(n), SC -- O(n)
vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    vector<ListNode *> ans(k);
    ListNode *curr = head;

    int len = lengthLL(head);

    int splitsize = len / k;

    int remainingParts = len % k;

    for (int i = 0; i < k; i++)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        int currsize = splitsize;

        if (remainingParts > 0)
        {
            remainingParts--;
            currsize++;
        }

        for (int j = 0; j < currsize; j++)
        {
            tail->next = new ListNode(curr->val);
            tail = tail->next;
            curr = curr->next;
        }

        ans[i] = dummy->next;
    }

    return ans;
}

vector<ListNode *> splitListToParts2(ListNode *head, int k)
{
    vector<ListNode *> ans(k);
    ListNode *curr = head, *prev = head;

    int len = lengthLL(head);

    // find split size
    int splitsize = len / k;

    int remainingParts = len % k;

    for (int i = 0; i < k; i++)
    {
        // start current part
        ListNode *dummy = curr;

        // determine the length of current part
        int currsize = splitsize;

        if (remainingParts > 0)
        {
            remainingParts--;
            currsize++;
        }

        // move to end of the part
        for (int j = 0; j < currsize; j++)
        {
            prev = curr;
            if (curr)
                curr = curr->next;
        }

        // cut off the link from the rest of the linked list
        if (prev)
            prev->next = NULL;

        ans[i] = dummy;
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode *head = createLL(arr);
    Display(head);
    vector<ListNode *> ans = splitListToParts2(head, 3);
    for (auto x : ans)
        Display(x);
    return 0;
}