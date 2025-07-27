// Problem: Boundary of Binary Tree
// LeetCode #545

// Description
// The boundary of a binary tree is the concatenation of:

// The root

// The left boundary

// The leaves (ordered from left-to-right)

// The reverse order of the right boundary

// Definitions:
// Left Boundary:

// Starts from the root’s left child.

// If a node in the left boundary has a left child, the left child is added.

// If a node has no left child but has a right child, the right child is added.

// The leftmost leaf is NOT part of the left boundary.

// Right Boundary:

// Starts from the root’s right child.

// Works like left boundary but in reverse direction.

// The rightmost leaf is NOT part of the right boundary.

// The right boundary is reversed when appended.

// Leaves:

// Nodes that have no children.

// The root is NOT considered a leaf for this problem.

// Input:
// root → The root of a binary tree.

// Output:
// Return a list of integers representing the boundary values of the tree in anti-clockwise order.

// Example 1:
// makefile
// Copy
// Edit
// Input:
//        1
//       / \
//      2   3
//     / \   \
//    4   5   6
//       / \
//      7   8

// Output: [1, 2, 4, 7, 8, 6, 3]

// Explanation:
// Root = [1]
// Left boundary = [2] (exclude 4 because it’s a leaf)
// Leaves = [4, 7, 8, 6]
// Right boundary (reverse) = [3]
// Final = [1, 2, 4, 7, 8, 6, 3]
// Example 2:
// makefile
// Copy
// Edit
// Input:
//   1
//    \
//     2
//    / \
//   3   4

// Output: [1, 3, 4, 2]

// Explanation:
// Root = [1]
// Left boundary = [] (no left child)
// Leaves = [3, 4]
// Right boundary (reverse) = [2]
// Final = [1, 3, 4, 2]
// Constraints:
// The number of nodes in the tree is in the range:
// 1 <= n <= 10^4

// -1000 <= Node.val <= 1000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return (node->left == nullptr && node->right == nullptr);
    }
    
    void addLeftBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->left;
        while(curr) {
            if(!isLeaf(curr)) res.push_back(curr->val);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void addLeaves(TreeNode* root, vector<int>& res) {
        if(!root) return;
        if(isLeaf(root)) {
            res.push_back(root->val);
            return;
        }
        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }
    
    void addRightBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->right;
        vector<int> tmp;
        while(curr) {
            if(!isLeaf(curr)) tmp.push_back(curr->val);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        reverse(tmp.begin(), tmp.end());
        for(int val : tmp) res.push_back(val);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        if(!isLeaf(root)) res.push_back(root->val);
        
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        
        return res;
    }
};
