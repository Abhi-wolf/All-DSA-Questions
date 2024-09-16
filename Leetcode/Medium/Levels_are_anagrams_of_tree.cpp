#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
};

TreeNode *makeTree(vector<int> arr)
{
    int n = arr.size(), i = 1;

    if (n == 0)
        return NULL;

    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> que;
    que.push(root);

    while (i < n)
    {
        TreeNode *p = que.front();
        que.pop();

        if (arr[i] != -1)
        {
            TreeNode *temp = new TreeNode(arr[i]);
            p->left = temp;
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
                TreeNode *temp = new TreeNode(arr[i]);
                p->right = temp;
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

void levelOrder(TreeNode *root)
{
    queue<TreeNode *> que;
    que.push(root);
    que.push(NULL);

    cout << "\n\n";
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
            cout << temp->val << " , ";
            if (temp->left)
                que.push(temp->left);

            if (temp->right)
                que.push(temp->right);
        }
    }

    cout << "\n\n";
}

bool anagram(TreeNode *root1, TreeNode *root2)
{
    // if (n != m)
    //     return false;

    queue<TreeNode *> que1, que2;
    unordered_map<int, int> freq1, freq2;

    que1.push(root1);
    que1.push(NULL);

    que2.push(root2);
    que2.push(NULL);

    while (!que1.empty() && !que2.empty())
    {
        TreeNode *temp1 = que1.front();
        TreeNode *temp2 = que2.front();
        que1.pop();
        que2.pop();

        if (temp1 == NULL && temp2 == NULL)
        {
            if (!que1.empty())
                que1.push(NULL);
            if (!que2.empty())
                que2.push(NULL);

            if (freq1.size() != freq2.size())
                return false;

            for (auto x : freq1)
            {
                cout << x.first << " , " << x.second << endl;
                if (freq2[x.first] != x.second)
                    return false;
            }

            freq1.clear();
            freq2.clear();
        }

        else
        {
            if ((temp1 && !temp2) || (!temp1 && temp2))
                return false;
        }

        if (temp1 != NULL)
        {
            freq1[temp1->val]++;
            if (temp1->left)
                que1.push(temp1->left);

            if (temp1->right)
                que1.push(temp1->right);
        }

        if (temp2 != NULL)
        {
            freq2[temp2->val]++;
            if (temp2->left)
                que2.push(temp2->left);

            if (temp2->right)
                que2.push(temp2->right);
        }
    }

    return true;
}

int main()
{
    vector<int> a1 = {1, 3, 2, -1, -1, 5, 4, -1, -1, -1, -1};
    vector<int> a2 = {1, 2, 3, 4, 5, -1, -1, -1, -1, -1, -1};

    TreeNode *r1 = makeTree(a1);
    TreeNode *r2 = makeTree(a2);

    levelOrder(r1);
    levelOrder(r2);

    cout << "Result = " << anagram(r1, r2) << endl;
    return 0;
}