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

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}


Node* searchNonRecursive(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}


Node* findMax(Node* root) {
    if (root == nullptr)
        return nullptr;

    while (root->right != nullptr)
        root = root->right;

    return root;
}


Node* findMin(Node* root) {
    if (root == nullptr)
        return nullptr;

    while (root->left != nullptr)
        root = root->left;

    return root;
}

Node* inorderSuccessor(Node* root, Node* target) {
    if (target == nullptr) return nullptr;

    // Case 1: Node has a right subtree
    if (target->right != nullptr)
        return findMin(target->right);

    // Case 2: No right subtree ? successor is an ancestor
    Node* successor = nullptr;
    while (root != nullptr) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        }
        else if (target->data > root->data) {
            root = root->right;
        }
        else
            break;
    }
    return successor;
}


Node* inorderPredecessor(Node* root, Node* target) {
    if (target == nullptr) return nullptr;

    // Case 1: Node has a left subtree
    if (target->left != nullptr)
        return findMax(target->left);

    // Case 2: No left subtree ? predecessor is an ancestor
    Node* predecessor = nullptr;
    while (root != nullptr) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        }
        else if (target->data < root->data) {
            root = root->left;
        }
        else
            break;
    }
    return predecessor;
}


int main() {
    Node* root = nullptr;

   
    int values[] = { 20, 10, 30, 5, 15, 25, 35 };
    for (int v : values)
        root = insert(root, v);

    int key = 15;
    Node* target = searchRecursive(root, key);

    cout << "Searching for " << key << " (Recursive): ";
    cout << (target ? "Found" : "Not Found") << endl;

    cout << "Searching for " << key << " (Non-Recursive): ";
    cout << (searchNonRecursive(root, key) ? "Found" : "Not Found") << endl;

    cout << "Minimum element in BST: " << findMin(root)->data << endl;
    cout << "Maximum element in BST: " << findMax(root)->data << endl;

    Node* suc = inorderSuccessor(root, target);
    if (suc)
        cout << "In-order Successor of " << key << " = " << suc->data << endl;
    else
        cout << "No In-order Successor exists for " << key << endl;

    Node* pred = inorderPredecessor(root, target);
    if (pred)
        cout << "In-order Predecessor of " << key << " = " << pred->data << endl;
    else
        cout << "No In-order Predecessor exists for " << key << endl;

    return 0;
}
