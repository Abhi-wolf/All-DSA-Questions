#include <iostream>
using namespace std;

/*
    Given the root node of a binary search tree and two integers low and high, return the sum of values
    of all nodes with a value in the inclusive range [low, high].

Example 1:
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

Example 2:
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.

Constraints:
The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.

*/

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *Insert(TreeNode *root, int val)
{
    if (root == NULL)
    {
        TreeNode *t = new TreeNode(val);
        return t;
    }

    if (root->data > val)
        root->left = Insert(root->left, val);
    else
        root->right = Insert(root->right, val);

    return root;
}

void Inorder(TreeNode *p)
{
    if (p == NULL)
        return;
    Inorder(p->left);
    cout << p->data << ", ";
    Inorder(p->right);
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    if (root == NULL)
        return 0;

    if (root->data >= low && root->data <= high)
        return root->data + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);

    else if (root->data < low)
        return rangeSumBST(root->right, low, high);

    else
        return rangeSumBST(root->left, low, high);
}

int main()
{
    TreeNode *root = NULL;
    int arr[] = {10, 5, 15, 3, 7, 13, 18, 1, 6};
    int sum = 0;
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        root = Insert(root, arr[i]);

    Inorder(root);
    sum = rangeSumBST(root, 6, 10);
    cout << "\n Range sum = " << sum << endl;
    return 0;
}