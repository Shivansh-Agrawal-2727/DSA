#include "0_binary_implementaion.cpp"
#include <algorithm>

// InOrder traversal through morris - LNR
// time complexity - O(n)
// space complexity - O(1)
vector<int> morrisIn(node *root)
{
    vector<int> ans;
    while (root)
    {
        // if left part doesn't exist
        if (!root->left)
        {
            ans.push_back(root->data); // note the data
            root = root->right;        // move to the right
        }
        // left part exist
        else
        {
            node *curr = root->left;
            while (curr->right && curr->right != root)
                curr = curr->right;

            // left subtree not traverse
            if (curr->right == NULL)
            {
                curr->right = root; // create the link
                root = root->left;  // move to left
            }
            // already traverse
            else
            {
                curr->right = NULL;        // remove link
                ans.push_back(root->data); // note the data
                root = root->right;        // move to the right
            }
        }
    }
    return ans;
}

// preOrder traversal through morris - NLR
// code part is same but note data while traversing not in already traversed
// time complexity - O(n)
// space complexity - O(1)
vector<int> morrisPre(node *root)
{
    vector<int> ans;
    while (root)
    {
        // if left part doesn't exist
        if (!root->left)
        {
            ans.push_back(root->data); // note the data
            root = root->right;        // move to the right
        }
        // left part exist
        else
        {
            node *curr = root->left;
            while (curr->right && curr->right != root)
                curr = curr->right;

            // left subtree not traverse
            if (curr->right == NULL)
            {
                ans.push_back(root->data); // note the data
                curr->right = root;        // create the link
                root = root->left;         // move to left
            }
            // already traverse
            else
            {
                curr->right = NULL; // remove link
                root = root->right; // move to the right
            }
        }
    }
    return ans;
}

// postOrder traversal through morris - LRN => pehle NRL nikalenge then usko reverse kar denge
vector<int> morrisPost(node *root)
{
    vector<int> ans;
    while (root)
    {
        // if right part doesn't exist
        if (!root->right)
        {
            ans.push_back(root->data); // note the data
            root = root->left;         // move to the left
        }
        // right part exist
        else
        {
            node *curr = root->right;
            while (curr->left && curr->left != root)
                curr = curr->left;

            // right subtree not traverse
            if (curr->left == NULL)
            {
                ans.push_back(root->data); // note the data
                curr->left = root;         // create the link
                root = root->right;        // move to right
            }
            // already traverse
            else
            {
                curr->left = NULL; // remove link
                root = root->left; // move to the left
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// flatten into linked list in preorder in which all left are null and right part is indicated next node
void flatten(node *root)
{
    while (root)
    {
        // if left part doesn't exist
        if (!root->left)
        {
            root = root->right;
        }
        // left part exist
        else
        {
            node *curr = root->left;
            while (curr->right)
                curr = curr->right;

            curr->right = root->right;
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
}
void print(node *root)
{
    while (root)
    {
        cout << root->data << " ";
        root = root->right;
    }
}
int main()
{
    cout << "enter root element: ";
    node *root = binaryTree();
    if (!root)
        cout << "binart tree is empty";
    else
    {
        vector<int> in = morrisIn(root);
        cout << "\ninOrder traversal through morris is: ";
        for (int i = 0; i < in.size(); i++)
        {
            cout << in[i] << " ";
        }

        vector<int> pre = morrisPre(root);
        cout << "\npreOrder traversal through morris is: ";
        for (int i = 0; i < pre.size(); i++)
        {
            cout << pre[i] << " ";
        }

        vector<int> post = morrisPost(root);
        cout << "\npostOrder traversal through morris is: ";
        for (int i = 0; i < post.size(); i++)
        {
            cout << post[i] << " ";
        }

        flatten(root);
        cout << "\nflatten into linked list: ";
        print(root);
    }
}