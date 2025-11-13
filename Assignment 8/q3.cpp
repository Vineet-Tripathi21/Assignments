#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};


Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        cout << "Duplicate not allowed: " << value << endl;

    return root;
}


Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}


Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return nullptr;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: One child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children → Replace with inorder successor
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int maxDepth(Node* root) {
    if (root == nullptr)
        return 0;

    int leftH = maxDepth(root->left);
    int rightH = maxDepth(root->right);

    return 1 + max(leftH, rightH);
}


int minDepth(Node* root) {
    if (root == nullptr)
        return 0;

    // If one child is NULL, return depth of other subtree + 1
    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}


void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main() {
    Node* root = nullptr;

    // Insert values to create BST
    int arr[] = { 40, 20, 10, 30, 60, 50, 70 };
    for (int v : arr)
        root = insert(root, v);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Delete example
    root = deleteNode(root, 20);
    cout << "After deleting 20: ";
    inorder(root);
    cout << endl;

    cout << "Maximum depth of BST = " << maxDepth(root) << endl;
    cout << "Minimum depth of BST = " << minDepth(root) << endl;

    return 0;
}

