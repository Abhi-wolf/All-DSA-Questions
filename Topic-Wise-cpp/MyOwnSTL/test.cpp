#include <iostream>
#include <queue>
#include "Create_Binary_Tree_from_array.h"
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        this->data = x;
        this->left = this->right;
    }
};

TreeNode *createTreeFromArray(int arr[], int n)
{
    if (n == 0)
        return NULL;

    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> que;
    int i = 1;
    que.push(root);
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
            i++;
        }
    }
    return root;
}

int main()
{
    int arr[] = {20, 30, 40, 50, 60, 70, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Node *root =
}