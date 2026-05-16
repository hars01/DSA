// #include<bits/stdc++.h>
// using namespace std;

// struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x){
//           val = x;
//           left = NULL;
//           right = NULL;
//      }
// };



// // Build Tree from Input (Level Order): 1 2 3 -1 -1 4 5 where -1 means NULL node
// // Function to build tree (level order)
// TreeNode* buildTree() {
//     int val;
//     cin >> val;

//     if (val == -1) return NULL;

//     TreeNode* root = new TreeNode(val);
//     queue<TreeNode*> q;
//     q.push(root);

//     while (!q.empty()) {
//         TreeNode* current = q.front();
//         q.pop();

//         int leftVal, rightVal;

//         if (!(cin >> leftVal)) break;
//         if (leftVal != -1) {
//             current->left = new TreeNode(leftVal);
//             q.push(current->left);
//         }

//         if (!(cin >> rightVal)) break;
//         if (rightVal != -1) {
//             current->right = new TreeNode(rightVal);
//             q.push(current->right);
//         }
//     }

//     return root;
// }

// void preorder(TreeNode* tree){
//      if (tree == NULL) return;

//      cout<<tree->val<<" ";
//      preorder(tree->left);
//      preorder(tree->right);
// }




// void printLevelOrder(TreeNode* root) {
//     if (root == NULL) return;

//     queue<TreeNode*> q;
//     q.push(root);

//     while (!q.empty()) {
//         int size = q.size();  // nodes in current level

//         for (int i = 0; i < size; i++) {
//             TreeNode* node = q.front();
//             q.pop();

//             cout << node->val << " ";

//             if (node->left) q.push(node->left);
//             if (node->right) q.push(node->right);
//         }

//         cout << endl; // move to next level
//     }
// }

// int main() {
   
//     cout << "Enter tree nodes (-1 for NULL): ";
    
//     TreeNode* root = buildTree();

//     printLevelOrder(root);

//     cout << "Preorder Traversal: ";
//     preorder(root);

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

// Tree Node Definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

// Build Tree (Level Order Input)
TreeNode* buildTree() {
    cout << "Enter root value: ";
    int val;
    cin >> val;

    if (val == -1) return NULL;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left child of " << current->val << ": ";
        cin >> leftVal;

        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->val << ": ";
        cin >> rightVal;

        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

// Preorder Traversal (Root → Left → Right)
void preorder(TreeNode* root) {
    if (root == NULL) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Level Order Traversal (Tree Structure)
void printLevelOrder(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    cout << "\nTree (Level Order):\n";

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            cout << node->val << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        cout << endl;
    }
}

int main() {
    TreeNode* root = buildTree();

    printLevelOrder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << endl;

    return 0;
}