#include "0_binary_implementaion.cpp"

// merge 2 maxheap in 1
// time complexity - O(m+n)
void heapify(vector<int> &m, int index, int size)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && m[left] > m[largest])
        largest = left;
    if (right < size && m[right] > m[largest])
        largest = right;

    if (largest != index)
    {
        swap(m[largest], m[index]);
        heapify(m, largest, size);
    }
}
vector<int> merge(vector<int> m1, vector<int> m2)
{
    vector<int> m;
    for (int i = 0; i < m1.size(); i++)
        m.push_back(m1[i]);
    for (int i = 0; i < m2.size(); i++)
        m.push_back(m2[i]);

    int n = m.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(m, i, n);

    return m;
}

// is binary tree a heap
// time complexity - O(n)
int count(node *root)
{
    if (!root)
        return 0;

    return 1 + count(root->left) + count(root->right);
}
bool CBT(node *root, int index, int size)
{
    if (!root)
        return 1;
    if (index >= size)
        return 0;

    return CBT(root->left, 2 * index + 1, size) && CBT(root->right, 2 * index + 2, size);
}
bool maxHeap(node *root)
{
    if (root->left)
    {
        if (root->data < root->left->data)
            return 0;

        if (!maxHeap(root->left)) // if maxHeap -> false, then return 0
            return 0;
    }
    if (root->right)
    {
        if (root->data < root->right->data)
            return 0;

        return maxHeap(root->right);
    }
    return 1; // if both child not exist
}
bool isHeap(node *root)
{
    // count nodes in tree
    int s = count(root);
    // CBT hai ya nahi
    if (!CBT(root, 0, s)) // CBT -> false, then return 0
        return 0;
    // parent >= child
    return maxHeap(root);
}

// BST to MaxHeap - parent > child && leftsubtree < rightsubtree [conditions]
// time complexity - O(n)
void inorder(node *root, vector<int> &ans)
{
    if (!root)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
void postorder(node *root, int &index, vector<int> &ans)
{
    if (!root)
        return;

    postorder(root->left, index, ans);
    postorder(root->right, index, ans);
    root->data = ans[index];
    index++;
}
void convertMaxheap(node *root)
{
    vector<int> ans;
    inorder(root, ans);
    int index = 0;
    postorder(root, index, ans);
}
int main()
{
    // vector<int> m1 = {10, 5, 6, 2};
    // vector<int> m2 = {12, 7, 9};
    // vector<int> m = merge(m1, m2);
    // cout << "after merging 2 maxheap is: ";
    // for (int i = 0; i < m.size(); i++)
    //     cout << m[i] << " ";

    cout << "enter root element: ";
    node *root = binaryTree();
    cout << "root is a binary heap or not: " << isHeap(root) << endl;
    convertMaxheap(root);
    inOrder(root);
}