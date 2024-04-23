#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

pair<int, int> swappedNode(int a[], int n) {
    int j = 0, k = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1])
            if (k == 0) {
                j = i;
                k = i - 1;
            } else
                j = i;
    }
    return {a[k], a[j]};
}
void restoreBST(Node* root, int inorder[], int n) {
    pair<int, int> p = swappedNode(inorder, n);
    if (root->data == p.first)
        root->data = p.second;
    if (root->data == p.second)
        root->data = p.first;
}
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    // HINT: inorder seq of BST is sorted increasing
    Node* root = new Node(5);
    root->left = new Node(3);
    root->left->right = new Node(4); // 4
    root->left->left = new Node(2);
    root->right = new Node(7);
    root->right->left = new Node(6); // 6
    root->right->right = new Node(8);
    int arr[] = {2, 3, 6, 5, 4, 7, 8};
    preorder(root);
    restoreBST(root, arr, 7);

    return 0;
}