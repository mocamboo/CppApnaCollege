#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void flatten(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->left != NULL)
    {
        flatten(root->left);
        Node *temp = root->right;
        root->right = root->left;

        root->left = NULL;
        Node *it = root->right;
        while (it->right != NULL)
        {
            it = it->right;
        }
        it->right = temp;
    }
    flatten(root->right);
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
    /*
                    1
                  /   \
                 2     3
                /     /  \
               4     6    5
                         /
                        7
                       /
                      8

*/
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->left->left = new Node(8);
    inorder(root);
    cout << endl;
    flatten(root);
    cout << endl;
    inorder(root);

    return 0;
}