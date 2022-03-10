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
bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->data != root2->data)
        return false;
    if (isIdentical(root1->left, root2->left) == false || isIdentical(root1->right, root2->right) == false)
        return false;
    return true;
}
int main()
{
    Node *root1 = new Node(5);
    root1->left = new Node(3);
    root1->left->right = new Node(4);
    root1->left->left = new Node(2);
    root1->right = new Node(7);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);
    // root1->right->right->right = new Node(9); // false

    Node *root2 = new Node(5);
    root2->left = new Node(3);
    root2->left->right = new Node(4);
    root2->left->left = new Node(2);
    root2->right = new Node(7);
    root2->right->left = new Node(6);
    root2->right->right = new Node(8);
    if (isIdentical(root1, root2) ? cout << "True" : cout << "False")
        ;
    return 0;
}