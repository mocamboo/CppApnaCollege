#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // case3
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    if (root->data > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        root->right = deleteNode(root->right, key);
    }
    return root;
}

// ___________________________Search__________________________________
Node *search(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}
Node *insertBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = NULL;
    root = insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 5);
    insertBST(root, 6);

    /*
              4
            /   \
           2     5
         /  \     \
        1    3     6

    */
    if (search(root, 1) != NULL)
        cout << " Do Exit 1" << endl;
    else
        cout << " Doesn't exit 1" << endl;

    inorder(root);
    root = deleteNode(root, 2);
    cout << endl;
    inorder(root);

    return 0;
}