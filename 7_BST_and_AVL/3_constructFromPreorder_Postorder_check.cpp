#include "0_binary_implementaion.cpp"

// construct BST from preOrder traversal - NLR
node *bst(vector<int> &pre, int &index, int lower, int upper)
{
    if (index == pre.size() || pre[index] < lower || pre[index] > upper) // lower < pre[index] < upper reion mein lie naa kare
        return NULL;

    node *root = new node(pre[index++]);
    root->left = bst(pre, index, lower, root->data);
    root->right = bst(pre, index, root->data, upper);
    return root;
}
node *bstfromPreorder(vector<int> pre)
{
    int index = 0;
    return bst(pre, index, INT8_MIN, INT8_MAX);
}

// construct BST from postOrder traversal - LRN
// ham isko reverse tarike se karenge NRL vector ko last se start karenge
node *bstpost(vector<int> &post, int &index, int lower, int upper)
{
    if (index < 0 || post[index] < lower || post[index] > upper) // lower < pre[index] < upper reion mein lie naa kare
        return NULL;

    node *root = new node(post[index--]);
    root->right = bstpost(post, index, root->data, upper);
    root->left = bstpost(post, index, lower, root->data);
    return root;
}
node *bstfromPostorder(vector<int> post)
{
    int index = post.size() - 1;
    return bstpost(post, index, INT8_MIN, INT8_MAX);
}

// check whether we can create the BST from preOrder or not
bool representBST(vector<int> arr)
{
    stack<int> lower, upper;
    lower.push(INT8_MIN);
    upper.push(INT8_MAX);
    int lowerBound, upperBound;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < lower.top()) // agar koi value lower bound se bhi chhoti hai to vo sabhi se chhoti hogi i.e. kisi bhi range mein fit nahi hogi
            return 0;

        while (arr[i] > upper.top()) // agar value upper se badi he to pop kar denge jisse ki range mein aa jae
        {
            lower.pop();
            upper.pop();
        }
        // agar saari condition thik hai to store value and pop
        lowerBound = lower.top();
        upperBound = upper.top();
        lower.pop();
        upper.pop();

        // right side
        lower.push(arr[i]);
        upper.push(upperBound);
        // left side
        lower.push(lowerBound);
        upper.push(arr[i]);
    }
    return 1;
}

// this will give segmentation fault because of recursion it stores in stack memory which is fixed ( not for larged values )

// void bst(vector<int> &arr, int &index, int lower, int upper)
// {
//     if (index == arr.size() || arr[index] < lower || arr[index] > upper) // lower < pre[index] < upper reion mein lie naa kare
//         return;

//     int value =arr[index++];
//     bst(arr, index, lower, value);
//     bst(arr, index, value, upper);
// }
// int representBST(vector<int>arr)
// {
//     int index = 0;
//     bst(arr, index, INT8_MIN, INT8_MAX);
//     return index==arr.size();
// }

int main()
{
    vector<int> pre = {20, 10, 6, 15, 12, 18, 30, 25, 40};
    node *root = bstfromPreorder(pre);
    cout << "inOrder traversal of created BST from preOrder is: ";
    inOrder(root);

    vector<int> post = {1, 7, 5, 50, 40, 10};
    node *root2 = bstfromPostorder(post);
    cout << "\ninOrder traversal of created BST from postOrder is: ";
    inOrder(root2);

    cout << "\ncheck whether we can create the BST from preOrder or not: " << representBST(pre);
}