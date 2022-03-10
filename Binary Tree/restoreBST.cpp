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

pair<int, int> swappedNode(int a[], int n)
{
    int j = 0, k = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
            if (k == 0)
                k = i;
            else
                j = i;
    }
}
void restoreBST(Node *root, int inorder[], int n)
{
}
int main()
{
    // HINT: inorder seq of BST is sorted increasing

    return 0;
}