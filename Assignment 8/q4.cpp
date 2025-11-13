#include <iostream>
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
    else
        root->right = insert(root->right, value);

    return root;
}


bool isBSTUntil(Node* root, int minVal, int maxVal) {
    if (root == nullptr)
        return true;

    // Node violates the min-max constraint
    if (root->data <= minVal || root->data >= maxVal)
        return false;

    // Check subtrees with updated min-max ranges
    return isBSTUntil(root->left, minVal, root->data) &&
        isBSTUntil(root->right, root->data, maxVal);
}


bool isBST(Node* root) {
    return isBSTUntil(root, INT_MIN, INT_MAX);
}


int main() {
    // Constructing a correct BST
    Node* root = nullptr;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);

    if (isBST(root))
        cout << "The given tree is a BST" << endl;
    else
        cout << "The given tree is NOT a BST" << endl;

    return 0;
}
