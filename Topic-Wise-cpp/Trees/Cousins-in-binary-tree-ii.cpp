#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins'
values. Two nodes of a binary tree are cousins if they have the same depth with different parents.
Return the root of the modified tree.
Note that the depth of a node is the number of edges in the path from the root node to it.

Example 1:

Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.

Example 2:
Input: root = [3,1,2]
Output: [0,0,0]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 3 does not have any cousins so its sum is 0.
- Node with value 1 does not have any cousins so its sum is 0.
- Node with value 2 does not have any cousins so its sum is 0.

Constraints:
The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 104*/

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

TreeNode *buildTree(vector<int> arr)
{
    int n = arr.size(), i = 1;

    if (n < 1)
        return NULL;

    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> que;
    que.push(root);

    while (i < n && !que.empty())
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

void siblingsSum(TreeNode *&root, int level, vector<int> &levelsum)
{
    if (!root || level >= levelsum.size())
        return;

    int sum = 0;
    if (root->left)
        sum += root->left->val;
    if (root->right)
        sum += root->right->val;

    if (root->left)
        root->left->val = levelsum[level] - sum;

    if (root->right)
        root->right->val = levelsum[level] - sum;

    siblingsSum(root->left, level + 1, levelsum);
    siblingsSum(root->right, level + 1, levelsum);
}

TreeNode *replaceValueInTree(TreeNode *root)
{
    vector<int> levelsum;
    queue<TreeNode *> que;
    int sum = 0;

    que.push(root);
    que.push(NULL);

    while (!que.empty())
    {
        TreeNode *p = que.front();
        que.pop();

        if (p == NULL)
        {
            levelsum.push_back(sum);
            sum = 0;

            if (!que.empty())
                que.push(NULL);
        }
        else
        {
            sum += p->val;

            if (p->left)
            {
                que.push(p->left);
            }
            if (p->right)
            {
                que.push(p->right);
            }
        }
    }

    root->val = 0;
    siblingsSum(root, 1, levelsum);
    return root;
}

void levelOrderTraversal(TreeNode *root)
{
    if (!root)
        return;

    cout << "\n\n";

    queue<TreeNode *> que;
    que.push(root);
    que.push(NULL);

    while (!que.empty())
    {
        TreeNode *temp = que.front();
        que.pop();

        if (temp == NULL)
        {
            cout << "\n";

            if (!que.empty())
                que.push(NULL);
        }
        else
        {
            cout << temp->val << ", ";

            if (temp->left)
                que.push(temp->left);

            if (temp->right)
                que.push(temp->right);
        }
    }

    cout << "\n\n";
}

int main()
{
    vector<int> arr = {5, 4, 9, 1, 10, -1, 7};
    TreeNode *root = buildTree(arr);
    root = replaceValueInTree(root);
    levelOrderTraversal(root);
    return 0;
}