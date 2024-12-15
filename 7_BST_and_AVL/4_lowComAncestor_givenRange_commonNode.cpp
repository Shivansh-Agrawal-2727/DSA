#include "0_binary_implementaion.cpp"

// find the lowest common ancestor in BST
node *LCA(node *root, int n1, int n2)
{
    if (!root)
        return NULL;

    if (n1 < root->data && n2 < root->data) // agar n1,n2 dono chhote hai to left mein check karo
        return LCA(root->left, n1, n2);
    else if (n1 > root->data && n2 > root->data) // agar n1,n2 dono bade hai to right mein check karo
        return LCA(root->right, n1, n2);
    else
        return root;
}

// print BST element in given range in ascending
void find(node *root, int l, int h, vector<int> &ans)
{
    if (!root)
        return;

    if (root->data > l && root->data > h) // agar left aur right dono se bada hai to left me jao
        find(root->left, l, h, ans);
    else if (root->data < l && root->data < h) // agar left aur right dono se chhota hai to right me jao
        find(root->right, l, h, ans);
    else // agar middle mein hai to inOrder mein print kara do
    {
        find(root->left, l, h, ans);
        ans.push_back(root->data);
        find(root->right, l, h, ans);
    }
}
vector<int> printNearNodes(node *root, int low, int high)
{
    vector<int> ans;
    find(root, low, high, ans);
    return ans;
}

// check whether BST contains Dead end or not
bool dead(node *root, int low, int high)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
    {
        if (root->data - low == 1 && high - root->data == 1)
            return 1;
        else
            return 0;
    }
    return (dead(root->left, low, root->data) || dead(root->right, root->data, high));
}
bool isdead(node *root)
{
    return dead(root, 0, INT8_MAX);
}

// find common nodes between two BST trees
// this method without using inorder but kaam same hai pehle left most par jaa rhe hai node check kara rahe hai phir right par jaa rahe hai
vector<int> findcommon(node *r1, node *r2)
{
    vector<int> ans;
    stack<node *> s1, s2;
    // left most elements ko sabse pehle stack ke andar dalo (initialise karo)
    while (r1)
    {
        s1.push(r1);
        r1 = r1->left;
    }
    while (r2)
    {
        s2.push(r2);
        r2 = r2->left;
    }

    while (!s1.empty() && !s2.empty())
    {
        // top element equal
        // then uske right mein jao or saare left most stack mein dalo
        if (s1.top()->data == s2.top()->data)
        {
            ans.push_back(s1.top()->data);
            r1 = s1.top()->right;
            s1.pop();
            r2 = s2.top()->right;
            s2.pop();
        }
        // s1 < s2
        else if (s1.top()->data < s2.top()->data)
        {
            r1 = s1.top()->right;
            s1.pop();
        }
        else // s1 > s2
        {
            r2 = s2.top()->right;
            s2.pop();
        }
        // right ke saare left most element stack mein daal rahe hai
        while (r1)
        {
            s1.push(r1);
            r1 = r1->left;
        }
        while (r2)
        {
            s2.push(r2);
            r2 = r2->left;
        }
    }
    return ans;
}

int main()
{
    cout << "enter root element: ";
    node *root = binaryTree();
    cout << "enter root element: ";
    node *root2 = binaryTree();

    // cout << "\nlowest common ancestor of given data is: " << LCA(root, 20, 40)->data;

    // vector<int> range = printNearNodes(root, 60, 80);
    // cout << "\nBST elements in given range is: ";
    // for (int i = 0; i < range.size(); i++)
    // {
    //     cout << range[i] << " ";
    // }

    // cout << "\ncheck whether BST contain dead end or not: " << isdead(root);

    vector<int> common = findcommon(root, root2);
    cout << "\ncommon nodes between two BST trees are: ";
    for (int i = 0; i < common.size(); i++)
    {
        cout << common[i] << " ";
    }
}