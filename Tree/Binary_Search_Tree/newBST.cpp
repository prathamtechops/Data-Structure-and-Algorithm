#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *insertInBST(node *root, int data)
{
    if (data == -1)
        return NULL;
    node *newNode = new node(data);
    if (root == NULL)
    {
        root = newNode;
        return root;
    }
    else if (data <= root->data)
        root->left = insertInBST(root->left, data);
    else
        root->right = insertInBST(root->right, data);
}
void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
node *minVal(node *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

node *maxVal(node *root)
{
    while (root->right)
    {
        root = root->right;
    }
    return root;
}

node *deleteInBST(node *&root, int value)
{
    if (root == NULL)
        return NULL;
    if (root->data == value)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right != NULL)
        {
            int min = minVal(root->right)->data;
            root->right->data = min;
            root->right = deleteInBST(root->right, min);
            return root;
        }
    }
    else if (root->data > value)
    {
        root->left = deleteInBST(root->left, value);
        return root;
    }
    else
    {
        root->right = deleteInBST(root->right, value);
        return root;
    }
}

int main(int argc, char const *argv[])
{
    node *root = NULL;
    root = insertInBST(root, 9);
    root = insertInBST(root, 16);
    root = insertInBST(root, 10);
    root = insertInBST(root, 98);
    root = insertInBST(root, 14);
    root = insertInBST(root, 1);
    root = insertInBST(root, 83);
    root = insertInBST(root, 6);

    inOrder(root);

    root = deleteInBST(root, 10);
    inOrder(root);
    return 0;
}