#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*

Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if
the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its
left child, right child, and parent.
Note: The tree contains unique values.

Examples :
Input:
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 8 is set on fire.
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.

Input:
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    /
 8    10
Target Node = 10
Output: 5

Expected Time Complexity: O(number of nodes)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ values of nodes ≤ 105
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
    int n = arr.size(), i = 0;

    if (n == 0)
        return NULL;

    queue<Node *> que;
    Node *root = new Node(arr[i++]);
    que.push(root);

    while (!que.empty() && i < n)
    {
        Node *temp = que.front();
        que.pop();

        if (i < n && arr[i] != -1)
        {
            temp->left = new Node(arr[i]);
            que.push(temp->left);
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            temp->right = new Node(arr[i]);
            que.push(temp->right);
        }
        i++;
    }

    return root;
}

void Inorder(Node *root)
{
    if (!root)
        return;
    Inorder(root->left);
    cout << root->data << " , ";
    Inorder(root->right);
}

Node *findNode(Node *root, unordered_map<Node *, Node *> &parent, int target, Node *prev)
{
    if (!root)
        return NULL;

    parent[root] = prev;

    if (root->data == target)
        return root;

    Node *left = findNode(root->left, parent, target, root);
    Node *right = findNode(root->right, parent, target, root);

    return left ? left : right;
}

int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> parent;
    unordered_map<Node *, int> visited;
    int time = 0;

    Node *targetNode = findNode(root, parent, target, NULL);
    queue<Node *> que;
    que.push(targetNode);
    visited[targetNode]++;

    while (!que.empty())
    {
        int size = que.size();

        for (int i = 0; i < size; i++)
        {
            Node *curr = que.front();
            que.pop();

            if (curr->left && visited.find(curr->left) == visited.end())
            {
                visited[curr->left]++;
                que.push(curr->left);
            }

            if (curr->right && visited.find(curr->right) == visited.end())
            {
                visited[curr->right]++;
                que.push(curr->right);
            }

            if (parent[curr] && visited.find(parent[curr]) == visited.end())
            {
                visited[parent[curr]]++;
                que.push(parent[curr]);
            }
        }
        time++;
    }
    return time - 1;
}

void preOrder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " , ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 8, -1, 9, -1, -1, -1, -1, -1, 10};
    Node *root = createTree(arr);
    cout << endl;
    Inorder(root);
    cout << endl;
    preOrder(root);
    cout << endl;

    cout << "Minimum time = " << minTime(root, 8) << endl;
    cout << "Minimum time = " << minTime(root, 10) << endl;
    cout << "Minimum time = " << minTime(root, 1) << endl;
    return 0;
}