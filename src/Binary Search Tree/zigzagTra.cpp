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
void zigzagTra(Node *root)
{
    if (root == NULL)
        return;
    deque<Node *> q;
    q.push_back(root);
    bool leftToright = true;
    while (!q.empty())
    {
        int n = q.size();
        if (leftToright)
        {
            cout << "LeftToRight: ";
            for (int i = 0; i < n; i++)
            {
                Node *node = q.front();
                q.pop_front();
                cout << node->data << " ";
                if (node->left)
                    q.push_back(node->left);
                if (node->right)
                    q.push_back(node->right);
            }
            leftToright = false;
            cout << endl;
        }
        else
        {
            cout << "RightToLeft: ";
            for (int i = 0; i < n; i++)
            {
                Node *node = q.back();
                q.pop_back();
                cout << node->data << " ";
                if (node->left)
                    q.push_front(node->right);
                if (node->right)
                    q.push_front(node->left);
            }
            cout << endl;
            leftToright = true;
        }
    }
}
void rightView(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            q.pop();
            if (i == n - 1)
                cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            cout << endl;
        }
    }
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->right = new Node(3);
    root->left->left = new Node(1);
    root->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    cout << "Right View:"
         << "\n";
    rightView(root);
    cout << endl;
    cout << "Level Order Traversl:" << endl;
    levelOrderTraversal(root);
    cout << "______________" << endl;

    cout << "Zigzag Traversal: " << endl;
    zigzagTra(root);
    return 0;
}