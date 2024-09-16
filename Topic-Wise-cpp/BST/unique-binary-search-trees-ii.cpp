#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes
of unique values from 1 to n. Return the answer in any order.

Example 1:
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Example 2:
Input: n = 1
Output: [[1]]

Constraints:

1 <= n <= 8
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

vector<TreeNode *> solve(int start, int end)
{
    vector<TreeNode *> ans;
    if (start > end)
    {
        ans.push_back(NULL);
        return ans;
    }

    // Iterate through all values from start to end to construct left and
    // right subtree recursively
    for (int i = start; i <= end; i++)
    {
        // Construct left subtree
        vector<TreeNode *> left = solve(start, i - 1);

        // Construct right subtree
        vector<TreeNode *> right = solve(i + 1, end);

        // loop through all left and right subtrees and connect them to ith
        // root
        for (int j = 0; j < left.size(); j++)
        {
            for (int k = 0; k < right.size(); k++)
            {
                // Create root with value i
                TreeNode *root = new TreeNode(i);

                // Connect left subtree rooted at left[j]
                root->left = left[j];

                // Connect right subtree rooted at right[k]
                root->right = right[k];

                ans.push_back(root);
            }
        }
    }

    return ans;
}

vector<TreeNode *> generateTrees(int n) { return solve(1, n); }

void preOrder(TreeNode *root)
{
    if (!root)
        return;

    cout << root->val << " , ";
    preOrder(root->left);
    preOrder(root->right);
}

void displayTrees(vector<TreeNode *> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        preOrder(ans[i]);
        cout << endl;
    }
}

int main()
{
    vector<TreeNode *> ans = generateTrees(5);
    displayTrees(ans);
    return 0;
}