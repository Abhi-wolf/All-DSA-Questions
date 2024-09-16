#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Given a Binary Tree (BT), convert it to a Doubly Linked List (DLL) in place. The left and right pointers in nodes
will be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the
same as the order of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the
head node of the DLL.

Note: h is the tree's height, and this space is used implicitly for the recursion stack.


Examples:
Input:
      1
    /  \
   3    2
Output:
3 1 2
2 1 3
Explanation: DLL would be 3<=>1<=>2

Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30
30 10 60 20 40
Explanation:  DLL would be 40<=>20<=>60<=>10<=>30.

Expected Time Complexity: O(no. of nodes)
Expected Space Complexity: O(height of the tree)

Constraints:
1 ≤ Number of nodes ≤ 105
0 ≤ Data of a node ≤ 105
*/

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree(vector<int> arr)
{
    int i = 1, n = arr.size();

    if (n == 0)
        return NULL;

    Node *root = new Node(arr[0]);
    queue<Node *> que;
    que.push(root);

    while (i < n && !que.empty())
    {
        Node *t = que.front();
        que.pop();

        if (i < n && arr[i] != -1)
        {
            t->left = new Node(arr[i]);
            que.push(t->left);
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            t->right = new Node(arr[i]);
            que.push(t->right);
        }
        i++;
    }

    return root;
}

void InorderTraversal(Node *root)
{
    if (!root)
        return;

    InorderTraversal(root->left);
    cout << root->data << ", ";
    InorderTraversal(root->right);
}

void Inorder(Node *root, Node *&head, Node *&tail)
{
    if (!root)
        return;

    Inorder(root->left, head, tail);

    if (!head)
    {
        head = root;
        tail = root;
        head->left = NULL;
    }
    else
    {
        tail->right = root;
        root->left = tail;
        tail = root;
    }

    Inorder(root->right, head, tail);
}

Node *bToDLL(Node *root)
{
    Node *head = NULL, *tail = NULL;
    Inorder(root, head, tail);
    return head;
}

void Display(Node *head)
{
    cout << endl;
    while (head)
    {
        cout << head->data << ", ";
        head = head->right;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 60};
    Node *root = createTree(arr);
    InorderTraversal(root);
    root = bToDLL(root);
    Display(root);
    return 0;
}