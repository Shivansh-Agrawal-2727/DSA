#include "0_binary_implementaion.cpp"

// left side node check karo + right side node check karo
bool isidentical(node *r1, node *r2)
{
    // base condition
    if (r1 == NULL && r2 == NULL)
        return 1;
    if ((!r1 && r2) || (r1 && !r2))
        return 0;

    // function condition
    if (r1->data != r2->data)
        return 0;

    return (isidentical(r1->left, r2->left) && isidentical(r1->right, r2->right));
}

// left ko right mein daldo & right ko left mein
void mirror(node *root)
{
    if (!root)
        return;

    node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// condition for balance tree -> -1 <= h(L)-h(R) <=1
int height(node *root, int &valid)
{
    if (!root)
        return 0;

    int l = height(root->left, valid);
    if (valid) // if left part mein hi valid = 0 aajata hai then no need to check
    {
        int r = height(root->right, valid);

        if (abs(l - r) > 1) // abs gives positive value
            valid = 0;

        return 1 + max(l, r);
    }
}
bool isbalance(node *root)
{
    int valid = 1;       // assume it is balance tree
    height(root, valid); // check for balance tree
    return valid;
}

// level order traversal in spiral form
vector<int> spiral(node *root)
{
    stack<node *> s1; // right to left
    stack<node *> s2; // left to right
    // initial direction is right to left in spiral
    s1.push(root);
    vector<int> ans;

    while (!s1.empty() || !s2.empty())
    {
        if (!s1.empty()) // right to left
        {
            while (!s1.empty())
            {
                node *temp = s1.top();
                s1.pop();
                ans.push_back(temp->data);
                // right to left ke order mein hi dalenge ltor stack mein
                if (temp->right)
                    s2.push(temp->right);
                if (temp->left)
                    s2.push(temp->left);
            }
        }
        if (!s2.empty())
        {
            while (!s2.empty())
            {
                node *temp = s2.top();
                s2.pop();
                ans.push_back(temp->data);
                // left to right ke order mein hi dalenge rtol stack mein
                if (temp->left)
                    s1.push(temp->left);
                if (temp->right)
                    s1.push(temp->right);
            }
        }
    }
    return ans;
}

// check if two nodes are cousin
bool parent(node *root, int a, int b)
{
    if (root == NULL)
        return 0;

    if (root->left && root->right)
    {
        if (root->left->data == a && root->right->data == b)
            return 1;
        if (root->left->data == b && root->right->data == a)
            return 1;
    }
    // chahe left me mil jae ya right mein, ek jagah bhi mil gaya to return 1 kar denge
    return (parent(root->left, a, b) || parent(root->right, a, b));
}
bool iscousin(node *root, int a, int b)
{
    queue<node *> q;
    q.push(root);

    int l1 = -1, l2 = -1;
    int level = 0;
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            node *temp = q.front();
            q.pop();

            if (temp->data == a)
                l1 = level;
            if (temp->data == b)
                l2 = level;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        level++;
        if (l1 != l2) // same level par nahi hai
            return 0;
        if (l1 = l2 == -1)
            return 0;
        if (l1 != -1 && l2 != -1) // dono ke lie level mil gaye hai
            break;
    }
    return !parent(root, a, b); // check parent same hai to 1 dega then ! lagakar 0 matlab cousin nahi hai
}

int main()
{
    cout << "enter root element of r1: ";
    node *r1 = binaryTree();

    cout << "\nenter root element of r2: ";
    node *r2 = binaryTree();

    if (r1 == NULL || r2 == NULL)
    {
        cout << "binary tree is empty";
    }
    else
    {
        int flag = isidentical(r1, r2);
        if (flag)
            cout << "\nboth tree are identical";
        else
            cout << "\nboth trees are not identical";

        cout << "\npreorder of r2 is: ";
        preOrder(r2);
        mirror(r2);
        cout << "\npreorder of r2 after mirroring is: ";
        preOrder(r2);

        int valid = isbalance(r1);
        if (valid)
            cout << "\ntree r1 is balanced";
        else
            cout << "\ntree r1 is unbalanced";

        vector<int> vec;
        vec = spiral(r1);
        cout << "\nlevel order traversal in spiral form of r1 is: ";
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }

        int a = 4, b = 5;
        int cousin = iscousin(r1, a, b);
        cout << endl;
        if (cousin)
            cout << a << " and " << b << " are cousin nodes in r1";
        else
        {
            cout << a << " and " << b << " are not cousin nodes in r1";
        }
    }
}