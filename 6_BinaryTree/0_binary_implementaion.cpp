#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;

    node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

node *binaryTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    node *temp = new node(x);

    cout << "enter the left child of " << x << ": ";
    temp->left = binaryTree();

    cout << "enter the right child of " << x << ": ";
    temp->right = binaryTree();

    return temp;
}

void preOrder(node *root)
{
    if (root == NULL)
        return;
    // node
    cout << root->data << " ";
    // left
    preOrder(root->left);
    // right
    preOrder(root->right);
}

void inOrder(node *root)
{
    if (root == NULL)
        return;
    // left
    inOrder(root->left);
    // node
    cout << root->data << " ";
    // right
    inOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
        return;
    // left
    postOrder(root->left);
    // right
    postOrder(root->right);
    // node
    cout << root->data << " ";
}

vector<int> levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        ans.push_back(temp->data);

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return ans;
}