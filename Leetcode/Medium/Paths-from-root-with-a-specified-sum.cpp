#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        this->data = x;
        this->left = this->right = NULL;
    }
};

Node *CreateTree(vector<int> arr)
{
    queue<Node *> que;
    int start = 0;
    int n = arr.size();

    Node *root = new Node(arr[start++]);
    que.push(root);

    while (start < n)
    {
        Node *currRoot = que.front();
        que.pop();

        int leftData = arr[start++];
        if (leftData != -1)
        {
            Node *temp = new Node(leftData);
            currRoot->left = temp;
            que.push(temp);
        }
        else
        {
            currRoot->left = NULL;
        }

        if (start < n)
        {
            int rightData = arr[start++];
            if (rightData != -1)
            {
                Node *temp = new Node(rightData);
                currRoot->right = temp;
                que.push(temp);
            }
            else
            {
                currRoot->right = NULL;
            }
        }
    }

    return root;
}

void Inorder(Node *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << ", ";
    Inorder(root->right);
}

void LevelOrder(Node *root)
{
    queue<Node *> que;
    que.push(root);
    que.push(NULL);

    while (!que.empty())
    {
        Node *temp = que.front();
        que.pop();

        if (temp == NULL)
        {
            cout << "\n";
            if (!que.empty())
                que.push(NULL);
        }

        else
        {
            cout << temp->data << ", ";
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
        }
    }
}

/*
Given a Binary tree and a sum S, print all the paths, starting from root, that sums upto the given sum.
Path not necessarily end on a leaf node.

Example 1:
Input : sum = 8
Input tree
         1
       /   \
     20      3
           /    \
         4       15
        /  \     /  \
       6    7   8    9

Output : 1 3 4
Explanation : Sum of path 1, 3, 4 = 8.

Example 2:
Input : sum = 38
Input tree
          10
       /     \
     28       13
           /     \
         14       15
        /   \     /  \
       21   22   23   24
Output :
10 28
10 13 15
Explanation :Sum of path 10, 28 = 38 and Sum of path 10, 13, 15 = 38.

Your task :
You don't have to read input or print anything. Your task is to complete the function printPaths()
that takes the root of the tree and sum as input and returns a vector of vectors containing the paths
that lead to the sum.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N^2)

Your Task :
1 <= N <= 2*103
-103 <= sum, Node.key <= 103
*/

void Solve(Node *root, int sum, vector<int> temp, vector<vector<int>> &ans)
{
    if (root == NULL)
        return;

    sum -= root->data;
    temp.push_back(root->data);

    if (sum == 0)
    {
        ans.push_back(temp);
    }

    vector<int> v1;
    v1 = temp;

    Solve(root->left, sum, v1, ans);
    Solve(root->right, sum, v1, ans);
}

vector<vector<int>> printPaths(Node *root, int sum)
{
    vector<vector<int>> ans;
    vector<int> temp;
    Solve(root, sum, temp, ans);
    return ans;
}

void Display2DArray(vector<vector<int>> res)
{
    cout << "2D Array \n";
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << ", ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    // vector<int> arr = {1, 20, 3, -1, -1, 4, 15, 6, 7, 8, 9};
    vector<int> arr = {10, 28, 13, -1, -1, 14, 15, 21, 22, 23, 24};

    Node *root = CreateTree(arr);
    Inorder(root);
    cout << endl;
    LevelOrder(root);

    vector<vector<int>> res = printPaths(root, 38);
    if (res.size() > 0)
        Display2DArray(res);
    else
        cout << "No Result \n";
    return 0;
}
