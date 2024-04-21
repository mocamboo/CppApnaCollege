#include <bits/stdc++.h>
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

int sumNode(Node *root)
{
    if (root == NULL)
        return 0;
    return sumNode(root->left) + sumNode(root->right) + 1;
}
void sumReplacement(Node *root)
{
    if (root == NULL)
        return;
    sumReplacement(root->left);
    sumReplacement(root->right);

    if (root->left != NULL)
        root->data += root->left->data;
    if (root->right != NULL)
        root->data += root->right->data;
}
void printInorder(Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    printInorder(root);
    sumReplacement(root);
    cout << endl;
    printInorder(root);

    return 0;
}