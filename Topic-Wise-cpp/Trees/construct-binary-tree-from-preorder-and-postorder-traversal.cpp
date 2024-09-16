#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree
of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the
binary tree.

If there exist multiple answers, you can return any of them.

Example 1:
Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

Example 2:
Input: preorder = [1], postorder = [1]
Output: [1]

Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
*/

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
};

/*
First node in preorder is always the root node. We will create a node root with data = pre[preindex].

Now, how to find the left subtree nodes? See, the second element in preorder is
the immediate left node of root. And in postorder, this (second element of
preorder) node is lying after all the elements of left subtree (as its
POSTorder.).

So we will find the index of that node( say its index) in postorder and
recursively build the tree. All the nodes ( postorder[0] to postorder[index]{
including } ) will form the left subtree and the nodes { postorder[index+1] to
postorder[end-1]) will contribute to the right subtree. We are not taking the
last node of POSTorder as it is the root node and has already used.
*/

TreeNode *build(vector<int> &preorder, vector<int> &postorder, int &preIndx, int start, int end)
{
    if (start > end || preIndx >= preorder.size())
        return NULL;

    TreeNode *node = new TreeNode(preorder[preIndx++]);

    if (start == end || preIndx == preorder.size())
    {
        return node;
    }

    int i = 0;
    for (i = start; i <= end; i++)
    {
        if (preorder[preIndx] == postorder[i])
            break;
    }

    if (i <= end)
    {
        node->left = build(preorder, postorder, preIndx, start, i);
        node->right = build(preorder, postorder, preIndx, i + 1, end - 1);
    }

    return node;
}

TreeNode *constructFromPrePost(vector<int> &preorder,
                               vector<int> &postorder)
{
    int preIndx = 0;

    return build(preorder, postorder, preIndx, 0, preorder.size() - 1);
}

void levelorder(TreeNode *root)
{
    queue<TreeNode *> que;
    que.push(root);
    que.push(NULL);

    while (!que.empty())
    {
        TreeNode *p = que.front();
        que.pop();

        if (p == NULL)
        {
            cout << endl;

            if (!que.empty())
                que.push(NULL);
        }
        else
        {
            cout << p->val << ", ";
            if (p->left)
                que.push(p->left);
            if (p->right)
                que.push(p->right);
        }
    }
    cout << endl;
}

int main()
{
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
    TreeNode *root = constructFromPrePost(preorder, postorder);
    levelorder(root);
    return 0;
}