#include <iostream>
#include <queue>
#include <utility>
#include <limits.h>
using namespace std;

/*
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b
where v = |a.val - b.val| and a is an ancestor of b.
A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

Example 1:
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

Example 2:
Input: root = [1,null,2,null,0,3]
Output: 3


Constraints:
The number of nodes in the tree is in the range [2, 5000].
0 <= Node.val <= 105
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
        this->left = this->right = NULL;
    }
};

// BUILD TREE USING GIVEN ARRAY
TreeNode *buildTree(int arr[], int n)
{
    if (n == 0)
        return NULL;

    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> que;
    que.push(root);
    int i = 1;

    while (i < n)
    {
        TreeNode *p = que.front();
        que.pop();

        if (i < n && arr[i] != -1)
        {
            p->left = new TreeNode(arr[i]);
            que.push(p->left);
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            p->right = new TreeNode(arr[i]);
            que.push(p->right);
        }
        i++;
    }

    return root;
}

//  LEVEL ORDER TRAVERSAL
void LevelOrder(TreeNode *root)
{
    if (root == NULL)
    {
        cout << "No Element present\n";
        return;
    }

    queue<TreeNode *> que2;
    que2.push(root);
    que2.push(NULL);

    while (!que2.empty())
    {
        TreeNode *t = que2.front();
        que2.pop();

        if (t == NULL)
        {
            cout << endl;
            if (!que2.empty())
                que2.push(NULL);
        }

        else
        {
            cout << t->val << ", ";
            if (t->left)
                que2.push(t->left);

            if (t->right)
                que2.push(t->right);
        }
    }

    cout << endl;
}

// INORDER TRAVERSAL
void Inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->val << ", ";
    Inorder(root->right);
}

// 1st SOLUTION
void InorderMinMax(TreeNode *p, int &large, int &small)
{
    if (p == NULL)
        return;

    InorderMinMax(p->left, large, small);

    if (small > p->val)
        small = p->val;

    if (large < p->val)
        large = p->val;

    InorderMinMax(p->right, large, small);
}

int maxAncestorDiff(TreeNode *root)
{
    queue<TreeNode *> que;
    que.push(root);

    int maxDiff = 0;

    while (!que.empty())
    {
        TreeNode *p = que.front();
        que.pop();

        int minEle = INT_MAX;
        int maxEle = INT_MIN;
        InorderMinMax(p, maxEle, minEle);

        if (minEle != INT_MAX)
        {
            int diff1 = abs(p->val - minEle);
            int diff2 = abs(p->val - maxEle);

            maxDiff = max(maxDiff, diff1);
            maxDiff = max(maxDiff, diff2);
        }

        if (p->left && (p->left->left || p->left->right))
            que.push(p->left);

        if (p->right && (p->right->left || p->right->right))
            que.push(p->right);
    }

    cout << "ans = " << maxDiff;

    return maxDiff;
}

// 2nd SOLUTION
pair<int, int> DFS(TreeNode *root, int &ans)
{
    if (root == NULL)
        return {INT_MAX, INT_MIN};

    auto left = DFS(root->left, ans);
    auto right = DFS(root->right, ans);

    int minEle = min(root->val, min(left.first, right.first));

    int maxEle = max(root->val, max(left.second, right.second));

    ans = max(ans, max(abs(minEle - root->val), abs(maxEle - root->val)));

    return {minEle, maxEle};
}

int maxAncestorDiff2(TreeNode *root)
{
    int maxDiff = 0;
    DFS(root, maxDiff);
    return maxDiff;
}

// MAIN FUNCTION
int main()
{
    int arr[] = {8, 3, 10, 1, 6, -1, 14, -1, -1, 4, 7, 13};
    // int arr[] = {1, -1, 2, -1, 0, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode *root = buildTree(arr, n);
    LevelOrder(root);
    Inorder(root);

    int res = maxAncestorDiff(root);
    cout << "\n\nMax Ancestor Difference 1 = " << res << endl;

    res = maxAncestorDiff2(root);
    cout << "\nMax Ancestor Difference 2 = " << res << endl;
    return 0;
}