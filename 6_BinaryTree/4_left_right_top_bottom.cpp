#include "0_binary_implementaion.cpp"

// METHOD - 1 through queue
vector<int> leftview(node *root)
{
    queue<node *> q;
    q.push(root);
    vector<int> ans;

    while (!q.empty())
    {
        // first element of current level
        ans.push_back(q.front()->data);
        int n = q.size();
        while (n--)
        {
            node *temp = q.front();
            q.pop();
            // right view ke lie right wala pehle aajaega then left wala (interchange)
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}

// METHOD - 2 through recurssion
void lview(node *root, int level, vector<int> &ans)
{
    if (!root)
        return;

    if (level == ans.size())
        ans.push_back(root->data);
    lview(root->left, level + 1, ans);
    lview(root->right, level + 1, ans);
}

// right view through recurssion
void rview(node *root, int level, vector<int> &ans)
{
    if (!root)
        return;

    if (level == ans.size())
        ans.push_back(root->data);
    rview(root->right, level + 1, ans);
    rview(root->left, level + 1, ans);
}

// top view of binary tree => METHOD - 1 using queue
void find(node *root, int pos, int &l, int &r)
{
    if (!root)
        return;
    // to find left most and right most element index
    l = min(l, pos);
    r = max(r, pos);

    find(root->left, pos - 1, l, r);
    find(root->right, pos + 1, l, r);
}
vector<int> topview(node *root)
{
    int l = 0, r = 0;
    find(root, 0, l, r);

    vector<int> ans(r - l + 1);
    vector<bool> filled(r - l + 1, 0); // declare all elements are 0

    queue<node *> q;
    queue<int> index;
    q.push(root);       // push root element
    index.push(-1 * l); // push root's element index

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        if (!filled[pos]) // filled[pos] == 0
        {
            filled[pos] = 1;
            ans[pos] = temp->data;
        }

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
    return ans;
}

// METHOD - 2 top view using recurssion
void top(node *root, int pos, vector<int> &ans, vector<int> &level, int l) // l=level (initial level)
{
    if (!root)
        return;
    // jiska level kam hoga usi ki value fill hogi
    if (level[pos] > l) // level[pos] < l -> for bottom view, jiska level jada hoga vo fill karenge i.e. level[pos] < l or int_min kardenge
    {
        ans[pos] = root->data;
        level[pos] = l;
    }
    top(root->left, pos - 1, ans, level, l + 1);
    top(root->right, pos + 1, ans, level, l + 1);
}
vector<int> tview(node *root)
{
    int l = 0, r = 0;
    find(root, 0, l, r);

    vector<int> ans(r - l + 1);
    vector<int> level(r - l + 1, INT32_MAX);
    top(root, -1 * l, ans, level, 0);
    return ans;
}

int main()
{
    cout << "enter root element: ";
    node *root = binaryTree();
    if (root == NULL)
        cout << "binary tree is empty";
    else
    {
        vector<int> vec = leftview(root);
        cout << "\nleft view of binary tree is: ";
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }

        vector<int> left;
        lview(root, 0, left);
        cout << "\nleft view of binary tree through recurssion: ";
        for (int i = 0; i < left.size(); i++)
        {
            cout << left[i] << " ";
        }

        vector<int> right;
        rview(root, 0, right);
        cout << "\nright view of binary tree through recurssion: ";
        for (int i = 0; i < right.size(); i++)
        {
            cout << right[i] << " ";
        }

        vector<int> top = topview(root);
        cout << "\ntop view of the binary tree is: ";
        for (int i = 0; i < top.size(); i++)
        {
            cout << top[i] << " ";
        }

        vector<int> t2 = tview(root);
        cout << "\ntop view of binary tree using recurssion is: ";
        for (int i = 0; i < t2.size(); i++)
        {
            cout << t2[i] << " ";
        }
    }
}