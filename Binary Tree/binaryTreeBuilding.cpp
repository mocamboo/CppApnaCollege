#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// function to serch current element in inorder array
int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
            return i;
    }
    return -1;
}

// main building function--
Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    static int idx = 0;

    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);
    if (start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder, inorder, start, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);

    return node;
}

// function to print tree in inorder--
// void printInorder(Node *root)
// {
//     if (root == NULL)
//         return;
//     printInorder(root->left);
//     cout << root->data << " ";
//     printInorder(root->right);
// }

void inorderPrint(Node *root)
{
    if (root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}
// -----------------------------------------------------------------------
Node *buildTree2(int postorder[], int inorder[], int start, int end)
{
    if (start > end)
        return NULL;
    static int idx = end;
    int curr = postorder[idx];
    idx--;
    Node *node = new Node(curr);
    if (start == end)
        return node;

    int pos = search(inorder, start, end, curr);
    node->right = buildTree2(postorder, inorder, pos + 1, end);
    node->left = buildTree2(postorder, inorder, start, pos - 1);
    return node;
}
int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    int postorder[] = {4, 2, 5, 3, 1};

    Node *root = buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);
    cout << endl;

    Node *root2 = buildTree2(preorder, inorder, 0, 4);
    inorderPrint(root);
    return 0;
}