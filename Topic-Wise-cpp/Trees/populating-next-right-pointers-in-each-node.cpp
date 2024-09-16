#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.
The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should
be set to NULL.
Initially, all next pointers are set to NULL.

Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point
to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers,
with '#' signifying the end of each level.

Example 2:
Input: root = []
Output: []

Constraints:

The number of nodes in the tree is in the range [0, 212 - 1].
-1000 <= Node.val <= 1000
*/

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node(int x)
    {
        this->val = x;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
    }
};

Node *buildTreeFromArray(vector<int> arr)
{
    int size = arr.size(), ind = 1;
    if (size == 0)
        return NULL;
    Node *root = new Node(arr[0]);
    queue<Node *> que;
    que.push(root);

    while (!que.empty() && ind < size)
    {
        Node *p = que.front();
        que.pop();

        if (ind < size && arr[ind] != -1)
        {
            p->left = new Node(arr[ind]);
            que.push(p->left);
        }
        ind++;

        if (ind < size && arr[ind] != -1)
        {
            p->right = new Node(arr[ind]);
            que.push(p->right);
        }
        ind++;
    }

    return root;
}

// FIRST METHOD
Node *connect1(Node *root)
{
    if (!root)
        return NULL;

    queue<Node *> que;
    que.push(root);
    que.push(NULL);
    vector<Node *> vec;

    while (!que.empty())
    {
        Node *p = que.front();
        que.pop();

        if (p == NULL)
        {
            for (int i = 0; i < vec.size() - 1; i++)
            {
                vec[i]->next = vec[i + 1];
            }
            vec.clear();
            if (!que.empty())
                que.push(NULL);
        }
        else
        {
            vec.push_back(p);

            if (p->left)
                que.push(p->left);
            if (p->right)
                que.push(p->right);
        }
    }

    return root;
}

// SECOND METHOD

Node *connect2(Node *root)
{
    if (!root)
        return NULL;

    queue<Node *> que;
    que.push(root);

    while (!que.empty())
    {
        // set rightNode to null initially
        Node *rightNode = NULL;

        // traversing each level
        for (int i = size(que); i; i--)
        {
            // pop a node from current level and,
            Node *curr = que.front();
            que.pop();

            // set its next pointer to rightNode
            curr->next = rightNode;

            // update rightNode as cur for next iteration
            rightNode = curr;

            // if a child exists
            // IMP: push right first to do right-to-left BFS
            if (curr->right)
            {
                que.push(curr->right);
                que.push(curr->left);
            }
        }
    }

    return root;
}

// THIRD METHOD -- RECURSIVE
Node *connect3(Node *root)
{
    if (!root)
        return NULL;

    if (root->left)
    {
        root->left->next = root->right;

        if (root->next)
        {
            root->right->next = root->next->left;
        }
    }

    connect3(root->left);
    connect3(root->right);

    return root;
}

void display(Node *root)
{
    queue<Node *> que;
    que.push(root);

    while (!que.empty())
    {
        Node *p = que.front();
        Node *temp = que.front();
        que.pop();

        while (p)
        {
            cout << p->val << " , ";
            p = p->next;
        }

        if (temp->left)
            que.push(temp->left);
    }

    cout << "\n";
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node *root = buildTreeFromArray(arr);
    Node *ans = connect1(root);
    display(ans);
    ans = connect2(root);
    display(ans);
    ans = connect3(root);
    display(ans);
    return 0;
}