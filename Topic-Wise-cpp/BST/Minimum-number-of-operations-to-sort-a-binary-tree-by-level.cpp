#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

/* You are given the root of a binary tree with unique values.
In one operation, you can choose any two nodes at the same level and swap their values.
Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.
The level of a node is the number of edges along the path between it and the root node.

Example 1:
Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
Output: 3
Explanation:
- Swap 4 and 3. The 2nd level becomes [3,4].
- Swap 7 and 5. The 3rd level becomes [5,6,8,7].
- Swap 8 and 7. The 3rd level becomes [5,6,7,8].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.

Example 2:
Input: root = [1,3,2,7,6,5,4]
Output: 3
Explanation:
- Swap 3 and 2. The 2nd level becomes [2,3].
- Swap 7 and 4. The 3rd level becomes [4,6,5,7].
- Swap 6 and 5. The 3rd level becomes [4,5,6,7].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.

Example 3:
Input: root = [1,2,3,4,5,6]
Output: 0
Explanation: Each level is already sorted in increasing order so return 0.

Constraints:
The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
All the values of the tree are unique.  */

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

TreeNode *buildTreeFrom_LevelOrder_Traversal(vector<int> levelOrder)
{
    int size = levelOrder.size(), start = 0;

    TreeNode *root = new TreeNode(levelOrder[0]);
    queue<pair<TreeNode *, int>> que;

    que.push(make_pair(root, start));

    while (!que.empty())
    {
        TreeNode *curr = que.front().first;
        int ind = que.front().second;
        que.pop();

        if (ind >= size)
            continue;

        int leftInd = 2 * ind + 1;
        int rightInd = 2 * ind + 2;

        if (leftInd < size && levelOrder[leftInd] != -1)
        {
            curr->left = new TreeNode(levelOrder[leftInd]);
            que.push(make_pair(curr->left, leftInd));
        }
        if (rightInd < size && levelOrder[rightInd] != -1)
        {
            curr->right = new TreeNode(levelOrder[rightInd]);
            que.push(make_pair(curr->right, rightInd));
        }
    }

    return root;
}

void levelOrder_Traversal(TreeNode *root)
{
    queue<TreeNode *> que;
    que.push(root);
    que.push(NULL);

    while (!que.empty())
    {
        TreeNode *curr = que.front();
        que.pop();

        if (curr == NULL)
        {
            cout << "\n";

            if (!que.empty())
                que.push(NULL);
        }
        else
        {
            cout << curr->val << ", ";
            if (curr->left)
                que.push(curr->left);
            if (curr->right)
                que.push(curr->right);
        }
    }
}

void inOrder_Traversl(TreeNode *root)
{
    if (!root)
        return;

    inOrder_Traversl(root->left);
    cout << root->val << ", ";
    inOrder_Traversl(root->right);
}

int getMinSwaps(vector<int> original)
{
    int swaps = 0;
    vector<int> target = original;
    sort(target.begin(), target.end());

    // Map to track current positions of values
    unordered_map<int, int> pos;
    for (int i = 0; i < original.size(); i++)
    {
        pos[original[i]] = i;
    }

    // For each position, swap until correct value is placed
    for (int i = 0; i < original.size(); i++)
    {
        if (original[i] != target[i])
        {
            swaps++;

            // Update position of swapped values
            int currpos = pos[target[i]];
            pos[original[i]] = currpos;
            swap(original[currpos], original[i]);
        }
    }

    return swaps;
}

// METHOD 01
int minimumOperations(TreeNode *root)
{
    queue<TreeNode *> que;
    vector<int> levelVals;
    que.push(root);
    que.push(NULL);

    int swaps = 0;

    while (!que.empty())
    {
        TreeNode *curr = que.front();
        que.pop();

        if (curr == NULL)
        {
            swaps += getMinSwaps(levelVals);

            if (!que.empty())
                que.push(NULL);

            levelVals.clear();
        }
        else
        {
            levelVals.push_back(curr->val);

            if (curr->left)
                que.push(curr->left);
            if (curr->right)
                que.push(curr->right);
        }
    }

    return swaps;
}

int main()
{
    vector<int> levelOrder1 = {1, 4, 3, 7, 6, 8, 5, -1, -1, -1, -1, 9, -1, 10};
    TreeNode *root1 = buildTreeFrom_LevelOrder_Traversal(levelOrder1);
    levelOrder_Traversal(root1);
    inOrder_Traversl(root1);
    cout << "\n\n RESULT1 = " << minimumOperations(root1) << endl;

    vector<int> levelOrder2 = {1, 3, 2, 7, 6, 5, 4};
    TreeNode *root2 = buildTreeFrom_LevelOrder_Traversal(levelOrder2);
    levelOrder_Traversal(root2);
    inOrder_Traversl(root2);
    cout << "\n\n RESULT2 = " << minimumOperations(root2) << endl;

    vector<int> levelOrder3 = {1, 2, 3, 4, 5, 6};
    TreeNode *root3 = buildTreeFrom_LevelOrder_Traversal(levelOrder3);
    levelOrder_Traversal(root3);
    inOrder_Traversl(root3);
    cout << "\n\n RESULT3 = " << minimumOperations(root3) << endl;

    return 0;
}