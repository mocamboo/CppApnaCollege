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
bool getPath(Node* root, int key, vector<int>& path) {
    if (root == NULL)
        return false;

    path.push_back(root->data);
    if (root->data == key) {
        return true;
    }

    if (getPath(root->left, key, path) || getPath(root->right, key, path)) {
        return true;
    }
    path.pop_back();
    return false;
}
int LCA(Node* root, int n1, int n2) {
    vector<int> path1, path2;

    if (!getPath(root, n1, path1) || !getPath(root, n2, path2)) {
        return -1;
    }
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++) {
        if (path1[i] != path2[i]) {
            break;
        }
    }
    return path1[i - 1];
}
// _________________________________OPTIMIZED__________________________________________________________
Node* LCA2(Node* root, int n1, int n2) {

    if (root == NULL) {
        return NULL;
    }
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);
    if (leftLCA && rightLCA) {
        return root;
    }
    if (leftLCA != NULL) {
        return leftLCA;
    }
    return rightLCA;
}

int main() {
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
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->left->left = new Node(8);

    int n1 = 6;
    int n2 = 8;
    cout << LCA(root, n1, n2) << endl;
    cout << "Opt : " << LCA2(root, n1, n2)->data << endl;

    return 0;
}
