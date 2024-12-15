#include "0_binary_implementaion.cpp"
#include <algorithm>

// preOrder traversal => NLR
vector<int> itpreorder(node *root)
{
    stack<node *> s;
    vector<int> ans;
    s.push(root);

    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        // jo stack mein baad mein likha jaata hai wo pehle access hota hai, islie left baad mein likha
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
    return ans;
}

// postOrder traversal => LRN -> pehle NRL nikalenge then reverse kardenge
vector<int> itpostorder(node *root)
{
    stack<node *> s;
    vector<int> ans;
    s.push(root);

    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        ans.push_back(temp->data);

        if (temp->left)
            s.push(temp->left);
        if (temp->right)
            s.push(temp->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// inoreder traversal => 1st time visit karunga to LNR, 2nd time visit to insert element
vector<int> itinorder(node *root)
{
    vector<int> ans;
    stack<node *> s;
    stack<bool> visited;
    s.push(root);
    visited.push(0);
    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        bool flag = visited.top();
        visited.pop();
        if (flag == 0)
        {
            // jo stack mein baad mein likha jaata hai wo pehle access hota hai, islie ulta likhenge LNR KO RNL
            if (temp->right)
            {
                s.push(temp->right);
                visited.push(0);
            }
            s.push(temp);
            visited.push(1);
            if (temp->left)
            {
                s.push(temp->left);
                visited.push(0);
            }
        }
        else
            ans.push_back(temp->data);
    }
    return ans;
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
        vector<int> pre = itpreorder(root);
        cout << "\npreOrder traversal through iterative is: ";
        for (int i = 0; i < pre.size(); i++)
        {
            cout << pre[i] << " ";
        }

        vector<int> post = itpostorder(root);
        cout << "\npostOrder traversal through iterative is: ";
        for (int i = 0; i < post.size(); i++)
        {
            cout << post[i] << " ";
        }

        vector<int> in = itinorder(root);
        cout << "\ninOrder traversal through iterative is: ";
        for (int i = 0; i < in.size(); i++)
        {
            cout << in[i] << " ";
        }
    }
}
