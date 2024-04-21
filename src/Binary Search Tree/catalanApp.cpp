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
int cat(int n)
{
    if (n <= 1)
        return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += cat(n - 1 - i) * cat(i);
    }
    return res;
}

vector<Node *> constructBST(int start, int end)
{
    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftSubtrees = constructBST(start, i - 1);
        vector<Node *> rightSubtrees = constructBST(i + 1, end);

        for (int j = 0; j < leftSubtrees.size(); j++)
        {
            Node *left = leftSubtrees[j];
            for (int k = 0; k < rightSubtrees.size(); k++)
            {
                Node *right = rightSubtrees[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
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

    vector<Node *> totalTrees = constructBST(1, 3);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << i + 1 << ": ";
        preorder(totalTrees[i]);
        cout << endl;
    }
    return 0;
}