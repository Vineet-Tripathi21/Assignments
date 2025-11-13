#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to generate BSTs from values [start, end]
vector<TreeNode*> generateTreesHelper(int start, int end) {
    vector<TreeNode*> result;

    // Base case: empty tree ? return vector containing NULL
    if (start > end) {
        result.push_back(NULL);
        return result;
    }

    // Choose root for each value from start to end
    for (int i = start; i <= end; i++) {
        // Recursively generate all left and right subtrees
        vector<TreeNode*> leftTrees = generateTreesHelper(start, i - 1);
        vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, end);

        // Combine left × right trees with i as root
        for (TreeNode* left : leftTrees) {
            for (TreeNode* right : rightTrees) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }

    return result;
}

// Main function: generate trees from 1 to n
vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTreesHelper(1, n);
}

// Utility: print preorder for verification
void preorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n = 3;
    vector<TreeNode*> trees = generateTrees(n);

    cout << "Total Unique BSTs = " << trees.size() << "\n\n";

    int idx = 1;
    for (TreeNode* t : trees) {
        cout << "Tree " << idx++ << ": ";
        preorder(t);
        cout << endl;
    }

    return 0;
}
