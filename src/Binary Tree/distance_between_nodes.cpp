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
Node* LCA(Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
    if (left != NULL && right != NULL) {
        return root;
    }
    if (left != NULL) {
        return left;
    }
    return right;
}
int findDis(Node* root, int k, int dis) {
    if (root == NULL)
        return -1;
    if (root->data == k) {
        return dis;
    }
    int left = findDis(root->left, k, dis + 1);
    if (left != -1) {
        return left;
    }
    return findDis(root->right, k, dis + 1);
}
int distBtwNodes(Node* root, int n1, int n2) {
    Node* lca = LCA(root, n1, n2);
    int d1 = findDis(lca, n1, 0);
    int d2 = findDis(lca, n2, 0);

    return d1 + d2;
}
int main() {

    /*
                        1
                      /   \
                     2     3
                    /     /  \
                   4     6    5
                       /  \   /
                      9   10|7
                            /
                           8

    */
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->left = new Node(9);
    root->right->left->right = new Node(10);
    root->right->right->left = new Node(7);
    root->right->right->left->left = new Node(8);

    int n1 = 4;
    int n2 = 8;
    cout << distBtwNodes(root, n1, n2); // 6

    return 0;
}