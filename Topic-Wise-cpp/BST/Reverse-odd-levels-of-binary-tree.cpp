#include <iostream>
#include <vector>
using namespace std;

/* Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become
[18,29,11,7,4,3,1,2].
Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.
The level of a node is the number of edges along the path between it and the root node.

Example 1:
Input: root = [2,3,5,8,13,21,34]
Output: [2,5,3,8,13,21,34]
Explanation:
The tree has only one odd level.
The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.

Example 2:
Input: root = [7,13,11]
Output: [7,11,13]
Explanation:
The nodes at level 1 are 13, 11, which are reversed and become 11, 13.

Example 3:
Input: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
Output: [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
Explanation:
The odd levels have non-zero values.
The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 2, 2, 2, 2, 1, 1, 1, 1 after the reversal.

Constraints:
The number of nodes in the tree is in the range [1, 214].
0 <= Node.val <= 105
root is a perfect binary tree.*/

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->val = data;
        this->left = this->right = NULL;
    }
};

int searchInorder(vector<int> &inorder, int instart, int inend, int key)
{
    for (int i = instart; i <= inend; i++)
    {
        if (inorder[i] == key)
            return i;
    }
    return -1;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &preorder, int instart, int inend, int &preind)
{
    if (instart > inend)
        return NULL;

    TreeNode *node = new TreeNode(preorder[preind++]);

    if (instart == inend)
        return node;

    int splitindex = searchInorder(inorder, instart, inend, node->val);

    if (splitindex != -1)
    {
        node->left = buildTree(inorder, preorder, instart, splitindex - 1, preind);
        node->right = buildTree(inorder, preorder, splitindex + 1, inend, preind);
    }

    return node;
}

void InorderTraversal(TreeNode *root)
{
    if (!root)
        return;

    InorderTraversal(root->left);
    cout << root->val << ", ";
    InorderTraversal(root->right);
}

void PreorderTraversal(TreeNode *root)
{
    if (!root)
        return;

    cout << root->val << ", ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

void dfs(TreeNode *leftChild, TreeNode *rightChild, int level)
{
    if (!leftChild || !rightChild)
        return;

    if (level % 2 == 0)
    {
        int temp = leftChild->val;
        leftChild->val = rightChild->val;
        rightChild->val = temp;
    }

    dfs(leftChild->left, rightChild->right, level + 1);
    dfs(leftChild->right, rightChild->left, level + 1);
}

TreeNode *reverseOddLevels(TreeNode *root)
{
    dfs(root->left, root->right, 0);
    return root;
}

int main()
{
    int preind = 0;
    vector<int> inorder = {5, 3, 6, 2, 7, 4, 8};
    vector<int> preorder = {2, 3, 5, 6, 4, 7, 8};

    TreeNode *root = buildTree(inorder, preorder, 0, inorder.size() - 1, preind);

    cout << "\n\n Inorder = ";
    InorderTraversal(root);
    cout << "\n\n Preorder = ";
    PreorderTraversal(root);

    root = reverseOddLevels(root);
    cout << "\n\n Inorder = ";
    InorderTraversal(root);
    cout << "\n\n Preorder = ";
    PreorderTraversal(root);
    return 0;
}