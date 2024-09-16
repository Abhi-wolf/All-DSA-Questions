#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int val)
{
    Node *temp = new Node();
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

Node *createTree(vector<int> arr)
{
    int n = arr.size(), i = 1;

    if (n == 0)
        return NULL;

    Node *root = newNode(arr[0]);
    queue<Node *> que;
    que.push(root);

    while (i < n)
    {
        Node *p = que.front();
        que.pop();

        if (arr[i] != -1)
        {
            Node *temp = newNode(arr[i]);
            p->left = temp;
            que.push(p->left);
        }
        else
        {
            p->left = NULL;
        }
        i++;

        if (i < n)
        {
            if (arr[i] != -1)
            {
                Node *temp = newNode(arr[i]);
                p->right = temp;
                que.push(p->right);
            }
            else
            {
                p->right = NULL;
            }
        }
        i++;
    }
    return root;
}

/* Consider Red lines of slope -1 passing between nodes (in following diagram). The diagonal sum in a binary tree is
the sum of all node datas lying between these lines. Given a Binary Tree of size n, print all diagonal sums.

Example 1:
Input:
         4
       /   \
      1     3
           /
          3
Output: 7 4

Example 2:
Input:
           10
         /    \
        8      2
       / \    /
      3   5  2
Output: 12 15 3

Your Task:
You don't need to take input. Just complete the function diagonalSum() that takes root node of the tree as parameter
and returns an array containing the diagonal sums for every diagonal present in the tree with slope -1.

Expected Time Complexity: O(nlogn).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 105
0 <= data of each node <= 104*/

vector<int> diagonalSum(Node *root)
{
    if (!root)
        return {};

    vector<int> ans;
    queue<Node *> que;
    que.push(root);

    while (!que.empty())
    {
        int n = que.size();
        int sum = 0;

        while (n--)
        {
            Node *temp = que.front();
            que.pop();

            while (temp)
            {
                sum += temp->data;

                if (temp->left)
                    que.push(temp->left);

                temp = temp->right;
            }
        }
        ans.push_back(sum);
    }
    return ans;
}

void Inorder(Node *p)
{
    if (p == NULL)
        return;

    Inorder(p->left);
    cout << p->data << " , ";
    Inorder(p->right);
}

void DiplayArr(vector<int> res)
{
    cout << endl;
    if (res.size() == 0)
        return;

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " , ";
    cout << endl;
}

int main()
{
    vector<int> arr = {10, 8, 2, 3, 5, 2};
    Node *root = createTree(arr);
    Inorder(root);
    vector<int> ans = diagonalSum(root);
    DiplayArr(ans);

    return 0;
}