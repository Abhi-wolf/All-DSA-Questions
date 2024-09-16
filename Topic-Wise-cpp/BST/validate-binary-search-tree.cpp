#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int x)
    {
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isValidInorder(TreeNode *root, TreeNode *&prev)
{
    if (!root)
        return true;

    if (!isValidInorder(root->left, prev))
        return false;

    if (prev && root->val <= prev->val)
        return false;

    prev = root;

    return isValidInorder(root->right, prev);
}

bool isValidBST(TreeNode *root)
{
    TreeNode *prev = NULL;
    return isValidInorder(root, prev);
}

TreeNode *buildTreeFromArray(vector<int> arr)
{
    int size = arr.size(), ind = 1;
    if (size == 0)
        return NULL;
    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty() && ind < size)
    {
        TreeNode *p = que.front();
        que.pop();

        if (ind < size && arr[ind] != -1)
        {
            p->left = new TreeNode(arr[ind]);
            que.push(p->left);
        }
        ind++;

        if (ind < size && arr[ind] != -1)
        {
            p->right = new TreeNode(arr[ind]);
            que.push(p->right);
        }
        ind++;
    }

    return root;
}

void Inorder(TreeNode *root)
{
    if (!root)
        return;
    Inorder(root->left);
    cout << root->val << ", ";
    Inorder(root->right);
}

void preOrder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << ", ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    vector<int> arr = {5, 1, 4, -1, -1, 3, 6};
    vector<int> arr2 = {2, 1, 3};
    TreeNode *root = buildTreeFromArray(arr);
    TreeNode *root2 = buildTreeFromArray(arr2);
    Inorder(root);
    cout << endl;
    preOrder(root);
    cout << endl;

    if (isValidBST(root))
        cout << "Yes valid BST \n";
    else
        cout << "Not a valid BST \n";

    if (isValidBST(root2))
        cout << "Yes valid BST \n";
    else
        cout << "Not a valid BST \n";
    return 0;
}