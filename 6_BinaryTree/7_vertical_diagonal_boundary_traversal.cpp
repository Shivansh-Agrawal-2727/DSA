#include "0_binary_implementaion.cpp"

// vertical order traversal
// time complexity - O(n)
void find(node *root, int pos, int &l, int &r)
{
    if (!root)
        return;
    // to find leftmost and rightmost part
    l = min(l, pos);
    r = max(r, pos);
    find(root->left, pos - 1, l, r);
    find(root->right, pos + 1, l, r);
}
vector<int> verticalOrder(node *root)
{
    int l = 0, r = 0;
    find(root, 0, l, r);

    queue<node *> q;
    queue<int> index;
    vector<vector<int>> positive(r + 1);
    // take abs because of negative index
    vector<vector<int>> negative(abs(l) + 1);
    q.push(root);
    index.push(0);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        if (pos >= 0)
            positive[pos].push_back(temp->data);
        else
            negative[abs(pos)].push_back(temp->data);

        if (temp->left)
        {
            q.push(temp->left);
            index.push(pos - 1);
        }
        if (temp->right)
        {
            q.push(temp->right);
            index.push(pos + 1);
        }
    }
    vector<int> ans;
    for (int i = negative.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < negative[i].size(); j++)
        {
            ans.push_back(negative[i][j]);
        }
    }
    for (int i = 0; i < positive.size(); i++)
    {
        for (int j = 0; j < positive[i].size(); j++)
        {
            ans.push_back(positive[i][j]);
        }
    }
    return ans;
}

// diagonal wise traversal
// time complexity - O(n^2)
void findleft(node *root, int pos, int &l)
{
    if (!root)
        return;
    l = max(pos, l);

    findleft(root->left, pos + 1, l);
    findleft(root->right, pos, l);
}
void findDiag(node *root, int pos, vector<vector<int>> &ans)
{
    if (!root)
        return;

    ans[pos].push_back(root->data);
    findDiag(root->left, pos + 1, ans);
    findDiag(root->right, pos, ans);
}
vector<int> diagonal(node *root)
{
    int l = 0;
    findleft(root, 0, l);
    vector<vector<int>> ans(l + 1);
    findDiag(root, 0, ans);
    vector<int> temp;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            temp.push_back(ans[i][j]);
        }
    }
    return temp;
}

// boundary traversal
void leftsub(node *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
        return;

    ans.push_back(root->data);
    if (root->left) // go to left
        leftsub(root->left, ans);
    else // if left is null then go to right
        leftsub(root->right, ans);
}
void leaf(node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }
    leaf(root->left, ans);
    leaf(root->right, ans);
}
void rightsub(node *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
        return;

    if (root->right) // go to right
        rightsub(root->right, ans);
    else // if right is null then go to left
        rightsub(root->left, ans);

    ans.push_back(root->data);
}
vector<int> boundary(node *root)
{
    vector<int> ans;
    // root element
    ans.push_back(root->data);

    // left boundary element ko daal do except leaf node
    leftsub(root->left, ans);

    // leaf ko insert kardo
    if (root->left || root->right)
        leaf(root, ans);

    // right boundary ko reverse order mein daal do except leaf node
    rightsub(root->right, ans);
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
        vector<int> vertical = verticalOrder(root);
        cout << "\nvertical order traversal is: ";
        for (int i = 0; i < vertical.size(); i++)
        {
            cout << vertical[i] << " ";
        }

        vector<int> diag = diagonal(root);
        cout << "\ndiagonal order traversal is: ";
        for (int i = 0; i < diag.size(); i++)
        {
            cout << diag[i] << " ";
        }

        vector<int> bound = boundary(root);
        cout << "\nboundary order traversal is: ";
        for (int i = 0; i < bound.size(); i++)
        {
            cout << bound[i] << " ";
        }
    }
}