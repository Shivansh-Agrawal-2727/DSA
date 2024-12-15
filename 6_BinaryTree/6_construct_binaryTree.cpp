#include "0_binary_implementaion.cpp"

// to create binary tree from preOrder and inOrder
// time complexity - O(n^2)
// to find the position of preOrder element in inOrder
int find(vector<int> &in, int target, int instart, int inend)
{
    for (int i = instart; i <= inend; i++)
    {
        if (target == in[i])
        {
            return i;
        }
    }
    return -1; // agar inorder & preorder alag tree ka hua to -1 se pata lag jaegi ye baat hame
}
node *buildTree(vector<int> &in, vector<int> &pre, int instart, int inend, int index)
{
    if (instart > inend)
    {
        return NULL;
    }
    node *root = new node(pre[index]);
    int pos = find(in, pre[index], instart, inend);

    // preOrder - NLR - pehle left build hoga phir right
    // divide in left and right with pos-1 and pos+1 respectively
    root->left = buildTree(in, pre, instart, pos - 1, index + 1);
    root->right = buildTree(in, pre, pos + 1, inend, index + (pos - instart) + 1);
    return root;
}

// to create binary tree from postOrder and inOrder
// time complexity - O(n^2)
node *buildTreebypost(vector<int> &in, vector<int> &post, int instart, int inend, int index)
{
    if (instart > inend)
    {
        return NULL;
    }
    node *root = new node(post[index]);
    int pos = find(in, post[index], instart, inend);

    // postOrder - LRN - reverse order mein lete hai NRL - isme pehle right build hota hai phir left, index last se chalu hota hai post ka
    // divide in left and right with pos-1 and pos+1 respectively
    root->right = buildTreebypost(in, post, pos + 1, inend, index - 1);
    root->left = buildTreebypost(in, post, instart, pos - 1, index - (inend - pos) - 1);
    return root;
}

int main()
{
    vector<int> in = {4, 2, 8, 5, 9, 1, 6, 3, 7, 10};
    vector<int> pre = {1, 2, 4, 5, 8, 9, 3, 6, 7, 10};
    int instart = 0;
    int inend = in.size() - 1;
    int index = 0;
    node *root = buildTree(in, pre, instart, inend, index);
    cout << "postOrder traversal is: ";
    postOrder(root);

    vector<int> post = {4, 8, 9, 5, 2, 6, 10, 7, 3, 1};
    int indx = post.size() - 1;
    node *root1 = buildTreebypost(in, post, instart, inend, indx);
    cout << "\npreOrder traversal is: ";
    preOrder(root1);
}