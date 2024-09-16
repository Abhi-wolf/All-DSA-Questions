#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of
the node values in the path equals targetSum. Each path should be returned as a list of the node values,
not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:
Input: root = [1,2], targetSum = 0
Output: []

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
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

void solve(TreeNode *root, int targetSum, vector<int> &temp, vector<vector<int>> &ans)
{
    if (!root)
        return;

    if (root && !root->left && !root->right && targetSum - root->val == 0)
    {
        temp.push_back(root->val);
        ans.push_back(temp);
        temp.pop_back();
        return;
    }

    temp.push_back(root->val);
    solve(root->left, targetSum - root->val, temp, ans);
    solve(root->right, targetSum - root->val, temp, ans);
    temp.pop_back();
}

void solve2(TreeNode *root, int targetSum, vector<int> &temp,
            vector<vector<int>> &ans)
{
    if (!root)
        return;

    temp.push_back(root->val);

    if (root && !root->left && !root->right && targetSum == root->val)
    {
        ans.push_back(temp);
    }

    solve2(root->left, targetSum - root->val, temp, ans);
    solve2(root->right, targetSum - root->val, temp, ans);
    temp.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve2(root, targetSum, temp, ans);
    return ans;
}

void Display2DArray(vector<vector<int>> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " , ";
        }
        cout << endl;
    }
}

int main()
{
    // vector<int> arr = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
    vector<int> arr = {-2, -1, -3};
    TreeNode *root = buildTreeFromArray(arr);
    vector<vector<int>> ans = pathSum(root, -5);
    Display2DArray(ans);
    return 0;
}