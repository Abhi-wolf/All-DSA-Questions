#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer
should be set to NULL.
Initially, all next pointers are set to NULL.

Example 1:
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its
next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers,
with '#' signifying the end of each level.

Example 2:
Input: root = []
Output: []

Constraints:

The number of nodes in the tree is in the range [0, 6000].
-100 <= Node.val <= 100
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

// SECOND METHOD -- RECURSIVE
Node *findNext(Node *root)
{
    if (!root)
        return NULL;
    if (root->left)
        return root->left;
    if (root->right)
        return root->right;

    return findNext(root->next);
}

Node *connect2(Node *root)
{
    if (!root)
        return NULL;

    if (root->left)
    {
        if (root->right)
            root->left->next = root->right;
        else
        {
            root->left->next = findNext(root->next);
        }
    }

    if (root->right)
    {
        root->right->next = findNext(root->next);
    }

    connect2(root->right);
    connect2(root->left);

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
    vector<int> arr = {1, 2, 3, 4, 5, -1, 7};
    Node *root = buildTreeFromArray(arr);
    Node *ans = connect1(root);
    display(ans);
    ans = connect2(root);
    display(ans);
    return 0;
}