#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be
pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.
Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

Example 1:
Input: root = [2,3,1,3,1,null,1]
Output: 2
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to
leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path
and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome)
and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).

Example 2:
Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1
Explanation: The figure above represents the given binary tree. There are three paths going from the root node
to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green
path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).

Example 3:
Input: root = [9]
Output: 1

Constraints:
    The number of nodes in the tree is in the range [1, 105].
    1 <= Node.val <= 9
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

TreeNode *createTreeFromArray(int arr[], int n)
{
    if (n == 0)
        return NULL;
    int i = 0;
    queue<TreeNode *> que;
    TreeNode *root = new TreeNode(arr[i]);
    que.push(root);
    i++;

    while (i < n)
    {
        TreeNode *p = que.front();
        que.pop();

        // left
        if (arr[i] != -1)
        {
            TreeNode *temp = new TreeNode(arr[i]);
            p->left = temp;
            que.push(p->left);
        }
        else
            p->left = NULL;

        i++;

        // right
        if (i < n && arr[i] != -1)
        {
            TreeNode *temp = new TreeNode(arr[i]);
            p->right = temp;
            que.push(p->right);
        }
        else
            p->right = NULL;

        i++;
    }

    return root;
}

void LevelOrder(TreeNode *root)
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
            cout << "\n";
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
}

void Inorder(TreeNode *p)
{
    if (p == NULL)
        return;

    Inorder(p->left);
    cout << p->val << ", ";
    Inorder(p->right);
}

// FIRST METHOD (MEMORY LIMIT EXHAUSTED)
void allPathsFromRootToLeaf(TreeNode *root, string path, vector<string> &paths)
{
    if (root == NULL)
        return;

    path += (root->val + '0');

    if (root->left == NULL && root->right == NULL)
    {
        paths.push_back(path);
        return;
    }

    allPathsFromRootToLeaf(root->left, path, paths);
    allPathsFromRootToLeaf(root->right, path, paths);
}

int pseudoPalindromicPaths(TreeNode *root)
{
    int ans = 0;
    vector<string> paths;
    string path = "";
    allPathsFromRootToLeaf(root, path, paths);

    for (int i = 0; i < paths.size(); i++)
    {
        cout << paths[i] << ", ";
        string str = paths[i];
        bool isPalindrom = true;
        unordered_map<char, int> um;

        for (int j = 0; j < str.size(); j++)
            um[str[j]]++;

        if (um.size() != 1 && str.size() % 2 == 0)
        {
            for (auto x : um)
                if (x.second % 2 != 0)
                    isPalindrom = false;
        }

        else if (um.size() != 1)
        {
            int notDivisibleBy2 = 0;
            for (auto x : um)
                if (x.second % 2 != 0)
                    notDivisibleBy2++;

            if (notDivisibleBy2 != 1)
                isPalindrom = false;
        }

        if (isPalindrom)
            ans++;
    }

    return ans;
}

// SECOND METHOD (BIT MANUPULATION)
/*
The idea is to keep the frequency of digit 1 in the first bit, 2 in the second bit, etc:
path ^= (1 << node.val).
Left shift operator is used to define the bit, and XOR operator - to compute the digit frequency.
XOR of zero and a bit results in that bit. XOR of two equal bits (even if they are zeros) results in a zero.
Hence, one could see the bit in a path only if it appears an odd number of times.

Now, to ensure that at most one digit has an odd frequency, one has to check that path is a power of two,
i.e., at most one bit is set to one. That could be done by turning off (= setting to 0) the
rightmost 1-bit:path & (path - 1) == 0.
*/
int dfs(TreeNode *root, int mask)
{
    if (root == NULL)
        return 0;

    mask ^= (1 << root->val);

    if (root->left == NULL && root->right == NULL)
        return (mask & (mask - 1)) == 0 ? 1 : 0;

    return dfs(root->left, mask) + dfs(root->right, mask);
}

int pseudoPalindromicPaths2(TreeNode *root)
{
    return dfs(root, 0);
}

int main()
{
    // int arr[] = {2, 3, 1, 3, 1, -1, 1};
    int arr[] = {2, 1, 1, 1, 3, -1, -1, -1, -1, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode *root = createTreeFromArray(arr, n);
    // LevelOrder(root);
    // Inorder(root);
    int res = pseudoPalindromicPaths(root);
    cout << "No of pseudo palindromic paths = " << res << endl;

    res = pseudoPalindromicPaths2(root);
    cout << "No of pseudo palindromic paths = " << res << endl;
    return 0;
}
