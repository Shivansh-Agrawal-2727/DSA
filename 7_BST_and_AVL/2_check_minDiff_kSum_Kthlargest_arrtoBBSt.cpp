#include "0_binary_implementaion.cpp"

// check if it is BST or not
// check in inorder because it is in ascending order
// every element is greater than from previous element
bool bst(node *root, int &prev)
{
    if (!root)
        return 1;

    bool l = bst(root->left, prev);
    if (l == 0) // if left is not bst then don't check right part
        return 0;

    if (root->data <= prev)
        return 0;
    prev = root->data;

    return bst(root->right, prev);
}
bool isBST(node *root)
{
    int prev = INT16_MIN;
    return bst(root, prev);
}

// minimum diff in BST
// check in inorder because it is in ascending order
void minDist(node *root, int &prev, int &ans)
{
    if (!root)
        return;

    minDist(root->left, prev, ans);
    if (prev != INT8_MIN)
        ans = min(ans, root->data - prev);
    prev = root->data;

    minDist(root->right, prev, ans);
}
int mindiff(node *root)
{
    int prev = INT8_MIN;
    int ans = INT8_MAX; // want minimum element so initialise with max
    minDist(root, prev, ans);
    return ans;
}

// sum of K smallest element
// check in inorder because it is in ascending order
void ksum(node *root, int &k, int &sum)
{
    if (!root)
        return;

    ksum(root->left, k, sum);
    k--;
    if (k >= 0)
        sum += root->data;
    else
        return;
    ksum(root->right, k, sum);
}
int sum(node *root, int k)
{
    int sum = 0;
    ksum(root, k, sum);
    return sum;
}

// Kth largest element
// check in reverse inorder i.e. RNL because it is in descending order
void klargest(node *root, int &k, int &ans)
{
    if (!root)
        return;

    klargest(root->right, k, ans);
    k--;
    if (k == 0)
        ans = root->data;
    if (k <= 0)
        return;
    klargest(root->left, k, ans);
}
int largest(node *root, int k)
{
    int ans;
    klargest(root, k, ans);
    return ans;
}

// sorted array into balanced binary tree preOrder
// if many preOrder exist then find lexographically smallest i.e. which have 1st element smallest
void arrtopreBST(vector<int> &arr, int start, int end, vector<int> &ans)
{
    if (start > end)
        return;

    int mid = (start + end) / 2;
    ans.push_back(arr[mid]);
    arrtopreBST(arr, start, mid - 1, ans); // left
    arrtopreBST(arr, mid + 1, end, ans);   // right
}
vector<int> arrtoBST(vector<int> &arr)
{
    vector<int> ans;
    arrtopreBST(arr, 0, arr.size() - 1, ans);
    return ans;
}

int main()
{
    cout << "enter root element: ";
    node *root = binaryTree();
    if (!root)
        cout << "binary tree is empty";
    else
    {
        cout << "\ntree is BST or not: " << isBST(root);

        cout << "\nminimum distance between BST nodes: " << mindiff(root);

        cout << "\nsum of K smallest element is: " << sum(root, 3);

        cout << "\nKth largest element is: " << largest(root, 3);
    }

    vector<int> arr = {1, 2, 3, 4, 5, 6};
    vector<int> pre = arrtoBST(arr);
    cout << "\nsorted array into balance BST preOrder is: ";
    for (int i = 0; i < pre.size(); i++)
    {
        cout << pre[i] << " ";
    }
}