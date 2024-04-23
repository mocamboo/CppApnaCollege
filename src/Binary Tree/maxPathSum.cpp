#include <bits/stdc++.h>
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
int maxPathSumUtil(Node* root, int& ans) {
    if (root == NULL)
        return 0;

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);
    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    ans = max(ans, nodeMax);
    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;
}
int maxPathSum(Node* root) {
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
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
                 /      /
                11     8
                  \
                   12

*/
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->left = new Node(9);
    root->right->left->left->left = new Node(11);
    root->right->left->left->left->right = new Node(12);
    root->right->left->right = new Node(10);
    root->right->right->left = new Node(7);
    root->right->right->left->left = new Node(8);
    cout << maxPathSum(root); // 61
    return 0;
}