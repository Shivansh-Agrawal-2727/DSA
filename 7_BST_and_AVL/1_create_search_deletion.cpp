#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// create binary search tree
// time complexity - O(n) to insert one node but for creating full bst then O(n^2)
// avg case - O(logn)
// space complexity - O(n)/O(h) - auxilary space
node *insert(node *root, int target)
{
    if (!root)
    {
        node *temp = new node(target);
        return temp;
    }
    // left side if target is less than root->data
    if (target < root->data)
        root->left = insert(root->left, target);

    // right side if target is greater than or equal to root->data
    else
        root->right = insert(root->right, target);

    return root;
}

// always give in sorted ascending order for bst
void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// searching in BST
// time complexity - O(h)/O(n)
// space complexity - O(h)/O(n)
bool search(node *root, int target)
{
    if (!root)
        return 0;

    if (root->data == target)
        return 1;

    if (target < root->data)
        return search(root->left, target);
    else
        return search(root->right, target);
}

// deletion in BST
// time complexity - O(n)
// space complexity - O(n)
node *deletion(node *root, int target)  // unique element
{
    // base condition target not present
    if (!root)
        return NULL;

    if (target < root->data)
    {
        root->left = deletion(root->left, target);
        return root;
    }
    else if (target > root->data)
    {
        root->right = deletion(root->right, target);
        return root;
    }
    else
    {
        // leaf node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // 1 child exist
        else if (!root->right) // left child exist
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left) // right child exist
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // both child exist
        else
        {
            // find the graetest element from left
            node *child = root->left;
            node *parent = root;
            // right most node tak pahuchna hai
            while (child->right)
            {
                parent = child;
                child = child->right;
            }

            if (root != parent)
            {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else // parent == root
            {
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
}

int main()
{
    vector<int> arr = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14, 3};
    node *root = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        root = insert(root, arr[i]);
    }

    cout << "inorder traversal is: ";
    inorder(root);

    cout << "\n"
         << search(root, 18);

    root=deletion(root,5);
    cout << "\ninorder traversal after deletion is: ";
    inorder(root);

}