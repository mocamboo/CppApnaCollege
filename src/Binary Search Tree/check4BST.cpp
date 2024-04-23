#include <bits/stdc++.h>
#include <cstddef>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool check(Node* root, int min, int max) {
    if (root == NULL)
        return true;
    if (root->data > min && root->data < max) {
        if (check(root->left, min, root->data) && check(root->right, root->data, max))

            return true;
    }
    return false;
}

int main() {
    Node* root1 = new Node(5);
    root1->left = new Node(6);
    root1->right = new Node(7);

    // Node *root2 = new Node(6);
    // root2->left = new Node(5);
    // root2->right = new Node(7);
    // if (check(root2))
    //     cout << "root2 is BST" << endl;
    // else
    //     cout << " root2 ni hai BST" << endl;
    if (check(root1, INT_MIN, INT_MAX))
        cout << "root1 bst hai" << endl;
    else
        cout << " root1 BST ni hai Bhai" << endl;

    return 0;
}
