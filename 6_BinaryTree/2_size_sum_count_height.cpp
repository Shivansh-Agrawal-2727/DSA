#include "0_binary_implementaion.cpp"

// METHOD - 1
// void totalNodes(node *root, int &count)
// {
//     if (root == NULL)
//         return;

//     count++;
//     // we can find sum also, write sum instead of count as sum += root->data
//     // we can count leafNodes also, write if(!root->left && !root->right) => count++ => return
//     totalNodes(root->left, count);
//     totalNodes(root->right, count);
// }
// int totalCount(node *root)
// {
//     int count = 0;
//     totalNodes(root, count);
//     return count;
// }

// METHOD - 2   => 1 + total nodes in left + total nodes in right
int totalCount(node *root)
{
    if (root == NULL)
        return 0;
    return (1 + totalCount(root->left) + totalCount(root->right));
}

// METHOD - 2   => khud ki value + left side ki value + right side ki value
int sum(node *root)
{
    if (!root)
        return 0;
    return (root->data + sum(root->left) + sum(root->right));
}

// METHOD - 2   => leaf node in left side + leaf node in right side
int leafCount(node *root)
{
    if (root == NULL)
        return 0;
    // leaf
    if (!root->left && !root->right)
        return 1;
    // non-leaf
    return (leafCount(root->left) + leafCount(root->right));
}

int nonleafCount(node *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 0;
    return (1 + nonleafCount(root->left) + nonleafCount(root->right));
}

int height(node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

// max no. of nodes in any level
int maxnodeinlevel(node *root)
{
    if (root == NULL)
        return 0;

    queue<node *> q;
    q.push(root);
    int maxcount = 0;

    while (!q.empty())
    {
        int levelsize = q.size();
        maxcount = max(maxcount, levelsize);

        for (int i = 0; i < levelsize; i++)
        {
            node *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return maxcount;
}

int main()
{
    cout << "enter root element: ";
    node *root = binaryTree();

    if (root == NULL)
    {
        cout << "binary tree is empty";
    }
    else
    {
        int count = totalCount(root);
        cout << "\nsize of the binary tree is: " << count;

        int total = sum(root);
        cout << "\nsum of all nodes is: " << total;

        int leaf = leafCount(root);
        cout << "\ntotal leaf nodes is: " << leaf;

        int non_leaf = nonleafCount(root);
        cout << "\ntotal non-leaf nodes is: " << non_leaf;

        int h = height(root);
        cout << "\nheight of the binary tree is: " << h;

        int m = maxnodeinlevel(root);
        cout << "\nmax no. of nodes in any level is: " << m;
    }
}
