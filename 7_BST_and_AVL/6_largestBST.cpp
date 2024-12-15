#include "0_binary_implementaion.cpp"

// class box
// {
// public:
//     bool BST;
//     int size;
//     int min, max;

//     box(int val)
//     {
//         BST = 1;
//         size = 1;
//         min = max = val;
//     }
// };
// box *find(node *root, int &totalsize)
// {
//     // leaf node
//     if (!root->left && !root->right)
//     {
//         totalsize = max(totalsize, 1); // minimum ek to hoga hi
//         return new box(root->data);
//     }

//     // only left side exist
//     if (!root->right && root->left)
//     {
//         box *head = find(root->left, totalsize);
//         if (head->BST && head->max < root->data)
//         {
//             head->size++;
//             head->max = root->data;
//             totalsize = max(head->size, totalsize);
//             return head;
//         }
//         else
//         {
//             head->BST = 0;
//             return head;
//         }
//     }
//     // only right side exist
//     else if (!root->left && root->right)
//     {
//         box *head = find(root->right, totalsize);
//         if (head->BST && head->min > root->data)
//         {
//             head->size++;
//             head->min = root->data;
//             totalsize = max(head->size, totalsize);
//             return head;
//         }
//         else
//         {
//             head->BST = 0;
//             return head;
//         }
//     }
//     // both exist
//     else
//     {
//         box *lefthead = find(root->left, totalsize);
//         box *righthead = find(root->right, totalsize);

//         if (lefthead->BST && righthead->BST && lefthead->max < root->data && righthead->min > root->data)
//         {
//             box *head = new box(root->data);
//             head->size += lefthead->size + righthead->size;
//             head->min = lefthead->min;
//             head->max = righthead->max;
//             totalsize = max(head->size, totalsize);
//             return head;
//         }
//         else
//         {
//             lefthead->BST = 0; // can also do from right
//             return lefthead;
//         }
//     }
// }

// METHOD - 2
class box
{
public:
    bool BST;
    int size;
    int min, max;

    box()
    {
        BST = 1;
        size = 0;
        min = INT8_MAX;
        max = INT8_MIN;
    }
};

box *find(node *root, int &totalsize)
{
    // root does not exist
    if (!root)
        return new box();

    // root exist
    box *lefthead = find(root->left, totalsize);
    box *righthead = find(root->right, totalsize);
    if (lefthead->BST && righthead->BST && lefthead->max < root->data && righthead->min > root->data)
    {
        box *head = new box();
        head->size = 1 + lefthead->size + righthead->size;
        head->min = min(lefthead->min, root->data);
        head->max = max(righthead->max, root->data);
        totalsize = max(head->size, totalsize);
        return head;
    }
    else
    {
        lefthead->BST = 0; // can also do from right
        return lefthead;
    }
}
int largestBST(node *root)
{
    int totalsize = 0;
    find(root, totalsize);
    return totalsize;
}

int main()
{
    cout << "enter root element: ";
    node *root = binaryTree();

    cout << "\nlargest bst size in binary tree is: " << largestBST(root);
}