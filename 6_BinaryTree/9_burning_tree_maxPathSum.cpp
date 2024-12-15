#include "0_binary_implementaion.cpp"

// burning tree
int burn(node *root, int &timer, int target)
{
    // exist naa kare
    if (!root)
        return 0;
    // exist kare
    // target node
    if (root->data == target)
        return -1;

    int left = burn(root->left, timer, target);
    int right = burn(root->right, timer, target);

    // burn ki condition
    if (left < 0)
    {
        timer = max(timer, abs(left) + right);
        return left - 1;
    }
    if (right < 0)
    {
        timer = max(timer, left + abs(right));
        return right - 1;
    }
    // height ko return;
    return 1 + max(left, right);
}
void find(node *root, int target, node *&burnNode)
{
    if (!root)
        return;
    if (root->data == target)
    {
        burnNode = root;
        return;
    }
    find(root->left, target, burnNode);
    find(root->right, target, burnNode);
}
int height(node *root)
{
    if (!root)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}
int minTime(node *root, int target)
{
    int timer = 0;
    burn(root, timer, target);

    // height of target if we consider it as root
    node *burnNode = NULL;
    find(root, target, burnNode);
    int h = height(burnNode) - 1;

    return max(timer, h);
}

// max path sum between 2 special nodes (special node is connected to only one node)
int pathsum(node *root, int &sum)
{
    if (!root)
        return 0;

    // leaf node - return data only
    if (!root->left && !root->right)
        return root->data;

    int left = pathsum(root->left, sum);
    int right = pathsum(root->right, sum);

    // left and right both exist
    if (root->left && root->right)
    {
        sum = max(sum, root->data + left + right);
        return root->data + max(left, right);
    }
    // only left exist
    if (root->left)
        return root->data + left;
    // only right exist
    if (root->right)
        return root->data + right;
}
int maxPathsum(node *root)
{
    int sum = INT16_MIN;
    int val = pathsum(root, sum);
    if (root->left && root->right)
        return sum;
    // root node hi special node hai to
    return max(val, sum);
}

int main()
{
    cout << "enter root elements: ";
    node *root = binaryTree();
    if (root == NULL)
        cout << "binary tree is empty";
    else
    {
        int target;
        cout << "enter the starting point of burning tree: ";
        cin >> target;
        int timer = minTime(root, target);
        cout << "\nminimum time to burn the tree is: " << timer << " seconds";

        int sum = maxPathsum(root);
        cout << "\nmax path sum b/w two special nodes is: " << sum;
    }
}