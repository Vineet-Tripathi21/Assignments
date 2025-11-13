#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to check if a node is a leaf
bool isLeaf(TreeNode* node) {
    return node != nullptr && node->left == nullptr && node->right == nullptr;
}

// Main function to compute sum of left leaves
int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr)
        return 0;

    int sum = 0;

    // Check if left child is a leaf
    if (isLeaf(root->left))
        sum += root->left->val;

    // Recurse left and right
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {
    

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Sum of left leaves = " << sumOfLeftLeaves(root);
    return 0;
}
