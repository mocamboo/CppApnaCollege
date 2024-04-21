#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right, *left;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int biggestBST(Node *root, int min, int max)
{
    if (root == NULL)
        return 0;
    if (root->data > min && root->data < max)
    {
        int left = biggestBST(root->left, min, root->data);
        int right = biggestBST(root->right, root->data, max);
        return left + right + 1;
    }
    return 0;
}
int main()
{
    Node *root = new Node(6);
    root->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left = new Node(99);
    root->right = new Node(7);
    root->right->left = new Node(13);
    root->right->right = new Node(12);
    root->right->right->right = new Node(17);
    root->right->right->left = new Node(11);
    cout << "Size of Biggest BST in BT is: " << biggestBST(root, INT_MIN, INT_MAX); // 7

    return 0;
}