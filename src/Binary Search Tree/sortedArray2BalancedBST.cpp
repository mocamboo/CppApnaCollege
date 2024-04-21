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
// int midEle(int arr[],int lo,int hi){

// }
Node *bbst(Node *root, int arr[], int lo, int hi)
{
    if (lo > hi)
        return NULL;
    // int mid = (lo + hi) / 2 + (lo + hi) % 2;
    int mid = (lo + hi) / 2;

    root = new Node(arr[mid]);
    root->left = bbst(root->left, arr, lo, mid - 1);
    root->right = bbst(root->right, arr, mid + 1, hi);
    return root;
}
void preorderPrint(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    // approach: look for middle element of cuurent array for root recursively
    Node *root = bbst(NULL, arr, 0, 4);
    preorderPrint(root);

    return 0;
}