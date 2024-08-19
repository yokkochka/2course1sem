/*
Option 8
1 Build a binary tree containing n = 14 nodes. Specify the key values ​​in the nodes using a random number
generator with a range D from 0 to 120 3 Ensure that the trees are traversed "bottom-up". 4 Search for the key
value by proximity from below.
*/

#include <time.h>

#include <iostream>
using namespace std;

int random();

int INT_MIN = -10000;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    int level;
    TreeNode(int val, int lvl) : key(val), left(nullptr), right(nullptr), level(lvl) {}
};

int findClosestBelow(TreeNode* root, int target) {
    int closestBelow = INT_MIN;

    while (root != nullptr) {
        if (root->key <= target) {
            closestBelow = max(closestBelow, root->key);
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return closestBelow;
}

TreeNode* insert(TreeNode* root, int key, int level) {
    if (root == nullptr) {
        return new TreeNode(key, level);
    }
    if (key < root->key) {
        root->left = insert(root->left, key, level + 1);
    } else if (key > root->key) {
        root->right = insert(root->right, key, level + 1);
    }
}

void bottomUpTraversal(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    bottomUpTraversal(node->left);
    bottomUpTraversal(node->right);
    cout << "Level " << node->level << ": " << node->key << endl;
}

int main() {
    time_t t;
    srand(time(&t));
    int n = 14;

    TreeNode* root = nullptr;

    cout << "\nNumbers: " << endl;
    for (int i = 0; i < n; ++i) {
        int key = random();
        cout << key << " ";
        root = insert(root, key, 1);
    }

    cout << "\n\nResult: " << endl;
    bottomUpTraversal(root);

    int targetValue;
    cout << "\nEnter the target value: ";
    cin >> targetValue;

    int closestBelowValue = findClosestBelow(root, targetValue);

    if (closestBelowValue == INT_MIN) {
        cout << "\nNo value below the target in the tree." << endl;
    } else {
        cout << "\nThe closest value below the target is: " << closestBelowValue << endl;
    }
}

int random() {
    int rnd = rand() % (120 - 0 + 1);
    if (rnd < 0) {
        rnd *= -1;
    }

    return rnd;
}
