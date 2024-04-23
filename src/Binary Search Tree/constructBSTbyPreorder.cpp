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

Node* constructBST(int preorder[], int* idx, int key, int min, int max, int n) {
    if (*idx >= n)
        return NULL;
    Node* root = NULL;
    if (key > min && key < max) {
        root = new Node(key);
        *idx = *idx + 1;
        // *idx++; Doesn't work
        if (*idx < n)
            root->left = constructBST(preorder, idx, preorder[*idx], min, key, n);
        if (*idx < n)
            root->right = constructBST(preorder, idx, preorder[*idx], key, max, n);
    }
    return root;
}
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    /*
                 10
                /  \
               2    13
              /     /
             1    11
    */
    // Node *root = new Node(10);
    // root->left = new Node(2);
    // root->left->left = new Node(1);
    // root->right = new Node(13);
    // root->right->left = new Node(11);
    int pre[] = {10, 2, 1, 13, 11};
    int min = INT_MIN;
    int max = INT_MAX;
    int idx = 0;
    Node* root = constructBST(pre, &idx, 10, min, max, 5);
    inorder(root);
    return 0;
}