#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

TreeNode *make_Tree(vector<int> arr)
{
    queue<TreeNode *> que;
    TreeNode *root = new TreeNode(arr[0]);
    que.push(root);
    int i = 1, n = arr.size();
    while (i < n)
    {
        TreeNode *p = que.front();
        que.pop();

        if (arr[i] != -1)
        {
            p->left = new TreeNode(arr[i]);
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
                p->right = new TreeNode(arr[i]);
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

void Inorder(TreeNode *root)
{
    if (!root)
        return;

    Inorder(root->left);
    cout << root->val << " , ";
    Inorder(root->right);
}

bool isLeaf(TreeNode *root)
{
    if (root && !root->left && !root->right)
        return true;
    return false;
}

TreeNode *removeLeafNodes(TreeNode *root, int target)
{
    if (!root)
        return nullptr;

    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    if (isLeaf(root) && root->val == target)
    {
        return nullptr;
    }

    return root;
}

void solve(TreeNode *&root, int target)
{
    if (!root)
        return;

    solve(root->left, target);
    solve(root->right, target);

    if (isLeaf(root) && root->val == target)
    {
        root = nullptr;
    }
}

TreeNode *removeLeafNodes2(TreeNode *root, int target)
{
    if (!root)
        return nullptr;

    solve(root, target);
    return root;
}

int main()
{
    vector<int> arr = {1, 2, 3, 2, -1, 2, 4};
    vector<int> arr2 = {1, 2, -1, 2, -1, 2};
    TreeNode *root = make_Tree(arr);
    TreeNode *root2 = make_Tree(arr2);
    Inorder(root);
    cout << "\n\n";
    Inorder(root2);
    root = removeLeafNodes(root, 2);
    root2 = removeLeafNodes(root2, 2);
    cout << "\n\n";
    Inorder(root);
    cout << "\n\n";
    Inorder(root2);
    return 0;
}