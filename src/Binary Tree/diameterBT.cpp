#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int ddiameter(Node* root, int* height) {
    if (root == NULL) {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int ldia = ddiameter(root->left, &lh);
    int rdia = ddiameter(root->right, &rh);
    int currdia = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currdia, max(ldia, rdia));
}
int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int h = 0;
    cout << ddiameter(root, &h);
    return 0;
}