#include <iostream>
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

// // METHOD-1  ( level wise creating nodes )

// int main()
// {
//     int x, first, second;
//     cout << "enter the root element: ";
//     cin >> x;

//     queue<node *> q;
//     node *root = new node(x);
//     q.push(root);

//     // build the binary tree
//     while (!q.empty())
//     {
//         node *temp = q.front();
//         q.pop();

//         // left node
//         cout << "enter the first child of " << temp->data << ": ";
//         cin >> first;
//         if (first == -1)
//         {
//             temp->left = NULL;
//         }
//         else
//         {
//             temp->left = new node(first);
//             q.push(temp->left);
//         }

//         // right node
//         cout << "enter the second child of " << temp->data << ": ";
//         cin >> second;
//         if (second == -1)
//         {
//             temp->right = NULL;
//         }
//         else
//         {
//             temp->right = new node(second);
//             q.push(temp->right);
//         }
//     }
// }

//             //        1
//             //    2       3
//             //  4   5   6   7

// METHOD-2  ( ek side se create karte chalenge i.e left )
// Time complexity - O(n)
// space complexity - O(height)  /  in worst case - O(n)
node *binaryTree()
{
    int x;
    cin >> x;
    // step-1
    if (x == -1)
        return NULL;

    // step-2 create node
    node *temp = new node(x);

    // step-3 create left side
    cout << "enter left child of " << x << " : ";
    temp->left = binaryTree();

    // step-4 create right side
    cout << "enter right child of " << x << " : ";
    temp->right = binaryTree();

    // step-5 return address
    return temp;
}

// In all cases, Time complexity - O(n)
// space complexity - O(height)  /  in worst case - O(n)

// pre-order -> NLR (node left right)
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

// in-order -> LNR
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

// post-order -> LRN
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

// level wise traversal
// time complexity - O(n);
// space complexity - O(n/2 + 1) -> O(n) [worst case]
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

int main()
{
    cout << "enter root element: ";
    node *root = binaryTree();

    cout << "\npreOrder traversal is: ";
    preOrder(root);

    cout << "\ninOrder traversal is: ";
    inOrder(root);

    cout << "\npostOrder traversal is: ";
    postOrder(root);

    cout << "\nlevelOrder traversal is: ";
    vector<int> level;
    level = levelOrder(root);
    for (auto i = 0; i < level.size(); i++)
    {
        cout << level[i] << " ";
    }
}