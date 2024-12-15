#include <iostream>
using namespace std;

// AVL, time complexity - O(logn) => for insertion, search, deletion
// O(nlogn) => for tree creation
class node
{
public:
    int data, height;
    node *left, *right;

    node(int value)
    {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

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

// insertion in AVL tree
int getheight(node *root)
{
    if (!root)
        return 0;

    return root->height;
}
int getbalance(node *root)
{
    return getheight(root->left) - getheight(root->right);
}

// right rotation
node *rightRotation(node *root)
{
    node *child = root->left;
    node *childright = child->right;

    child->right = root;
    root->left = childright;

    // update height
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;
}
// left rotation
node *leftRotation(node *root)
{
    node *child = root->right;
    node *childleft = child->left;

    child->left = root;
    root->right = childleft;

    // update height
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;
}

node *insert(node *root, int key)
{
    // does not exist
    if (!root)
        return new node(key);

    // exist
    if (key < root->data) // left side
        root->left = insert(root->left, key);
    else if (key > root->data) // right side
        root->right = insert(root->right, key);
    else // duplicates element are not allowed
        return root;

    // update height
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // check balance
    int balance = getbalance(root);

    if (balance > 1 && key < root->left->data) // LL case
    {
        return rightRotation(root); // top par rotation
    }
    else if (balance > 1 && root->left->data < key) // LR case
    {
        root->left = leftRotation(root->left); // middle par rotation
        return rightRotation(root);            // top par rotation
    }
    else if (balance < -1 && root->right->data < key) // RR case
    {
        return leftRotation(root); // top par rotation
    }
    else if (balance < -1 && key < root->right->data) // RL case
    {
        root->right = rightRotation(root->right); // middle par rotation
        return leftRotation(root);                // top par rotation
    }
    else // no unbalancing
    {
        return root;
    }
}

// deletion in AVL tree
node *deletion(node *root, int key)
{
    if (!root)
        return NULL;

    if (key < root->data) // left side
        root->left = deletion(root->left, key);
    else if (key > root->data) // right side
        root->right = deletion(root->right, key);
    else
    {
        // leaf node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // only one child exist
        else if (root->left && !root->right) // only left exist
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left && root->right) // only right exist
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // both child exist
        else
        {
            // right side smallest element
            node *curr = root->right;
            while (curr->left)
            {
                curr = curr->left;
            }

            // here we use short cut method by replacing but if we have to delete node then use that method which we used in BST
            root->data = curr->data;
            root->right = deletion(root->right, curr->data);
        }
    }
    // update the height
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // check balance
    int balance = getbalance(root);

    // left side
    if (balance > 1)
    {
        if (getbalance(root->left) >= 0) // LL
            return rightRotation(root);
        else // LR
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    // right side
    else if (balance < -1)
    {
        if (getbalance(root->right) <= 0) // RR
            return leftRotation(root);
        else // RL
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    else
        return root;
}

int main()
{
    // duplicates elements not allowed
    node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    cout << "preorder is: ";
    inOrder(root);

    deletion(root, 5);

    cout << "\npreorder after deletion is: ";
    inOrder(root);
}