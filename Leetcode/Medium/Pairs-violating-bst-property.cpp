#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <climits>
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

Node *makeTree(vector<int> arr)
{
    int n = arr.size(), i = 1;
    if (n == 0)
        return NULL;

    Node *root = new Node(arr[0]);
    queue<Node *> que;
    que.push(root);

    while (!que.empty() && i < n)
    {
        Node *temp = que.front();
        que.pop();

        if (arr[i] != -1)
        {
            temp->left = new Node(arr[i]);
            que.push(temp->left);
        }
        i += 1;

        if (i < n && arr[i] != -1)
        {
            temp->right = new Node(arr[i]);
            que.push(temp->right);
        }
        i++;
    }

    return root;
}

void Inorder(Node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " , ";
    Inorder(root->right);
}

// to check if node is greater than its left child and less than its right child
void isBST(Node *root, int &cnt)
{
    if (!root)
        return;
    if ((root->left && root->left->data > root->data) || (root->right && root->right->data < root->data))
        cnt++;

    isBST(root->left, cnt);
    isBST(root->right, cnt);
}

void maxLeftValue(Node *root, int &mx)
{
    if (!root)
        return;

    mx = max(mx, root->data);
    maxLeftValue(root->left, mx);
    maxLeftValue(root->right, mx);
}

void minRightValue(Node *root, int &mi)
{
    if (!root)
        return;

    mi = min(mi, root->data);
    maxLeftValue(root->left, mi);
    maxLeftValue(root->right, mi);
}

void nodesWithLesserValueThanMaxEleOfLeft(Node *root, int mx, unordered_set<int> &st)
{
    if (!root)
        return;

    if (root->data < mx)
        st.insert(root->data);

    nodesWithLesserValueThanMaxEleOfLeft(root->left, mx, st);
    nodesWithLesserValueThanMaxEleOfLeft(root->right, mx, st);
}

void nodesWithGreaterValueThanMinEleOfRight(Node *root, int mx, unordered_set<int> &st)
{
    if (!root)
        return;

    if (root->data > mx)
        st.insert(root->data);

    nodesWithGreaterValueThanMinEleOfRight(root->left, mx, st);
    nodesWithGreaterValueThanMinEleOfRight(root->right, mx, st);
}

int pairsViolatingBST(Node *root)
{
    unordered_set<int> st;
    if (root == NULL || (!root->left && !root->right))
        return 0;

    int mx = INT_MIN;
    maxLeftValue(root->left, mx);
    int mi = INT_MAX;
    minRightValue(root->right, mi);

    queue<Node *> que;
    return st.size();
}

int main()
{
    vector<int> arr = {10, 50, 40, -1, -1, 20, 30, -1, -1, -1, -1};
    Node *root = makeTree(arr);
    Inorder(root);
    cout << "Answer = " << pairsViolatingBST(root);

    arr.clear();
    cout << "\n\n";
    arr = {80, 40, 30, 70, -1, 60, 70};
    root = makeTree(arr);
    Inorder(root);
    cout << "Answer = " << pairsViolatingBST(root);
    return 0;
}