#include "0_binary_implementaion.cpp"

// merge 2 BST trees in 1
// void inorder(node *root, vector<int> &ans)
// {
//     if (!root)
//         return;

//     inorder(root->left, ans);
//     ans.push_back(root->data);
//     inorder(root->right, ans);
// }
// vector<int> merge(node *r1, node *r2)
// {
//     vector<int> ans1, ans2, ans;
//     inorder(r1, ans1);
//     inorder(r2, ans2);
//     // merge two vector into 1 vector in ascending order
//     int i = 0, j = 0;
//     while (i < ans1.size() && j < ans2.size())
//     {
//         if (ans1[i] < ans2[j])
//             ans.push_back(ans1[i++]);
//         else
//             ans.push_back(ans2[j++]);
//     }
//     // bache hue elements ko print kara lia agar kisi vector mein reh gaya ho to
//     while (i < ans1.size())
//     {
//         ans.push_back(ans1[i++]);
//     }
//     while (j < ans2.size())
//     {
//         ans.push_back(ans2[j++]);
//     }
//     return ans;
// }

// METHOD -2 through iterative
vector<int> merge2(node *r1, node *r2)
{
    stack<node *> s1, s2;
    vector<int> ans;
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
    while (!s1.empty() || !s2.empty())
    {
        if (s2.empty()) // s2 empty hai to s1 ke bache hue element saare daal do ans mein
        {
            while (!s1.empty())
            {
                ans.push_back(s1.top()->data);
                s1.pop();
            }
        }
        else if (s1.empty()) // s1 empty hai to s2 ke bache hue element saare daal do ans mein
        {
            while (!s2.empty())
            {
                ans.push_back(s2.top()->data);
                s2.pop();
            }
        }
        else
        {
            if (s1.top()->data < s2.top()->data) // s1 < s2
            {
                ans.push_back(s1.top()->data);
                r1 = s1.top()->right; // uske right mein jao (or saare left most stack mein dalo) -> ye chij aage karenge
                s1.pop();
            }
            else if (s1.top()->data > s2.top()->data) // s1 > s2
            {
                ans.push_back(s2.top()->data);
                r2 = s2.top()->right;
                s2.pop();
            }
            else // s1 = s2
            {
                ans.push_back(s1.top()->data);
                ans.push_back(s2.top()->data);
                r1 = s1.top()->right;
                s1.pop();
                r2 = s2.top()->right;
                s2.pop();
            }

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
    }

    return ans;
}

// fixing of two nodes by inorder morris traversal for space complexity O(1)
void fixingbst(node *root)
{
    node *curr = NULL;
    node *first = NULL, *second = NULL;
    node *last = NULL, *present = NULL;
    if (!root)
        return;

    while (root)
    {
        if (!root->left) // left does not exist
        {
            last = present;
            present = root;
            if (last && last->data > present->data) // matlab gadbad hai, ascending ki bajae dec. ho gya
            {
                if (!first) // agar do baar gadbad hai to first wala mein koi change nahi hoga but second wale hoga
                    first = last;
                second = present;
            }
            root = root->right;
        }
        else
        {
            curr = root->left;
            while (curr->right && curr->right != root)
            {
                curr = curr->right;
            }

            if (!curr->right) // not traversed
            {
                curr->right = root;
                root = root->left;
            }
            else // already traversed
            {
                curr->right = NULL;
                last = present;
                present = root;
                if (!last && last->data > present->data) // matlab gadbad hai, ascending ki bajae dec. ho gya
                {
                    if (!first) // agar do baar gadbad hai to first wala mein koi change nahi hoga but second wale hoga
                        first = last;
                    second = present;
                }
                root = root->right;
            }
        }
    }
    // int num = first->data;
    // first->data = second->data;
    // second->data = num;
    swap(first->data,second->data);
}

int main()
{
    // cout << "enter root element: ";
    // node *r1 = binaryTree();
    // cout << "\nenter root element: ";
    // node *r2 = binaryTree();

    // vector<int> m = merge2(r1, r2);
    // cout << "\nmerge two BST into one is: ";
    // for (int i = 0; i < m.size(); i++)
    // {
    //     cout << m[i] << " ";
    // }

    cout << "enter root element: ";
    node *root = binaryTree();

    cout << "\ninorder traversal before fixing two nodes: ";
    inOrder(root);
    fixingbst(root);
    cout << "\ninorder traversal after fixing two nodes: ";
    inOrder(root);
}